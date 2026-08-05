import socket

#creates a server socket using an IPv4 address and Datagrams which corresponds to the UDP protocol 
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#binds to my PCs IPv4 at the chosen 5005 port
server.bind(('192.168.1.248', 5005))

#creates a while true loop to contiously wait for received msgs
while True:
    #gets back the received data and address of the device that sent it 
    data, addr = server.recvfrom(2048)
    #decodes the received data
    print(data.decode(), addr)