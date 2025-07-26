#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : WirelessAP Client (AppB) – Socket Listener           ###
###                 Listens for broadcasted updates from AppA via UDP    ###
###  Date         : 03-05-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import socket

class WirelessAPClient:
    """
    A client that listens for incoming messages from AppA using UDP socket.
    This represents the receiver of Wireless Access Point updates.
    """

    def __init__(self, host='127.0.0.1', port=12345):
        """
        Initializes the client with host and port, and prepares socket.
        """
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def bind_socket(self):
        """
        Binds the socket to host and port.
        """
        try:
            self.socket.bind((self.host, self.port))
            print(f"📶 AppB Socket Client listening on {self.host}:{self.port}\n")
        except Exception as e:
            print(f"⚠️ Error binding socket: {e}")

    def listen_for_messages(self):
        """
        Continuously listens for messages from AppA and prints them.
        """
        while True:
            try:
                data, addr = self.socket.recvfrom(1024)
                message = data.decode()
                print(f"\n📨 Received message from AppA:\n{message}", flush=True)
            except KeyboardInterrupt:
                choice = input("\n🔁 Ctrl+C detected. Continue monitoring? (y/n): ").strip().lower()
                if choice == 'n':
                    print("🛑 Socket listening terminated.")
                    break
                elif choice != 'y':
                    print("⚠️ Invalid input. Enter 'y' or 'n'.")

def main():
    """
    Initializes the WirelessAP socket client and begins listening for updates.
    """
    client = WirelessAPClient()
    client.bind_socket()
    client.listen_for_messages()

if __name__ == "__main__":
    main()