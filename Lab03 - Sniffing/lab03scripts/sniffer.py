from scapy.all import *
import sys

#take input from the user - how many packets we will take
numpackets=int(sys.argv[1])
print("Lucas Fulmer, packet sniffer")

#printing the TCP field
print("TCP Header")
ls(TCP)

#printing the ICMP field
print('ICMP Header')
ls(ICMP)
print('\nGo to a site in your browswer')

#
packets=sniff(count=numpackets)
print('\nHere are the first {} packets'.format(numpackets))
packets.show()

print('\nhexdump')
for packet in range(0,numpackets-1):
	hexdump(packets[packet])

ans,unans=sr(IP(dst="www.python.org", ttl=5)/ICMP())
print(ans)
print(unans)
