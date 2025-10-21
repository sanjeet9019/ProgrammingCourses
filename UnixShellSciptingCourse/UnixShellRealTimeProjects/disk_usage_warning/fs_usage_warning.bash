#!/bin/bash

##################################################################
# Script Name : fs_usage_warning.sh
# Description : A disk usage monitoring script that sends email
#               alerts when ext2/ext4 file systems exceed a
#               specified usage threshold.
# Author      : Sanjeet Prasad
# Email       : sanjeet8.23@gmail.com
# Date        : October 19, 2025
##################################################################

TEST_MODE=false  # Enable with --test

# Function to display usage instructions
show_usage() {
    echo "Usage: $0 [--test] [-c capacity-percentage] email-address [email-address] ..."
    exit 1
}

# Function to send email using mailx and here-document
send_email() {
    local subject="$1"
    local body="$2"
    for email in "${emails[@]}"; do
        if $TEST_MODE; then
            echo "$subject"
            echo "$body"
        fi
        mailx -s "$subject" "$email" <<EOF
$body
EOF
    done
}

# Main function starts from here
main() {
    local capacity=60
    emails=()

    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case "$1" in
            --test)
                TEST_MODE=true
                ;;
            -c)
                shift
                if [[ "$1" =~ ^[0-9]+$ ]]; then
                    capacity="$1"
                else
                    echo "Error: Invalid capacity percentage."
                    show_usage
                fi
                ;;
            -*)
                echo "Error: Unknown option $1"
                show_usage
                ;;
            *)
                emails+=("$1")
                ;;
        esac
        shift
    done

    if [[ ${#emails[@]} -eq 0 ]]; then
        echo "Error: No email addresses provided."
        show_usage
    fi

	# Disk snapshot block (only in normal mode)
    if ! $TEST_MODE; then
        echo "----------------------------------------"
        echo "Current ext2/ext4 Disk Usage Snapshot:"
        df -T -P | awk '
        BEGIN { print "Filesystem\tType\tSize\tUsed\tAvail\tUse%\tMounted on" }
        $2 ~ /^ext[24]$/ { print $0 }
        '
        if ! df -T -P | awk '$2 ~ /^ext2$/' | grep -q .; then
            echo "Note: ext2 is not supported on this system."
        fi
        echo "----------------------------------------"
    fi
    # Process disk usage
    df -T -P | awk -v cap="$capacity" '
    $2 ~ /^ext[24]$/ {
        usage = $(NF-1)
        gsub(/%/, "", usage)
        if (usage >= cap) {
            fs = $NF
            header = "Filesystem\tType\tSize\tUsed\tAvail\tUse%\tMounted on"
            if (usage >= 90) {
                subject = "Critical Warning: the file system " fs " is greater than or equal to 90% capacity"
            } else {
                subject = "Warning: the file system " fs " is above " cap " % used"
            }
            print subject "\n" header "\n" $0 > "/dev/stdout"
        }
    }' | while IFS= read -r line; do
        if [[ "$line" =~ ^(Warning|Critical) ]]; then
            subject="$line"
            body=""
        elif [[ "$line" =~ ^Filesystem ]]; then
            body="$line"
        else
            body="$body"$'\n'"$line"
            send_email "$subject" "$body"
        fi
    done
}

main "$@"
exit 0
