/*Step-by-Step Guide
Step 1: Install libpcap
Ensure libpcap is installed on your development environment. For Debian-based systems, you can install it using:

sudo apt-get install libpcap-dev

Step 2: Write the Packet Filter Program
Create a C++ program that uses libpcap to capture packets and apply filtering logic.

C++ */

#include <iostream>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <cstring>
#include <set>

// List of blocked IP addresses
std::set<std::string> blocked_ips = {"192.168.1.100", "203.0.113.0"};

// List of blocked domains (requires DNS resolution, simplified here)
std::set<std::string> blocked_domains = {"example.com", "anonymous-site.com"};

// Function to check if an IP should be blocked
bool isBlockedIP(const std::string& ip) {
    return blocked_ips.find(ip) != blocked_ips.end();
}

// Callback function for packet handling
void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // Assuming Ethernet header is 14 bytes
    const struct ip* ip_header = (struct ip*)(packet + 14);

    // Extract source and destination IP addresses
    struct in_addr src_addr = ip_header->ip_src;
    struct in_addr dest_addr = ip_header->ip_dst;

    std::string src_ip = inet_ntoa(src_addr);
    std::string dest_ip = inet_ntoa(dest_addr);

    // Check if the packet should be blocked
    if (isBlockedIP(src_ip) || isBlockedIP(dest_ip)) {
        std::cout << "Blocking packet from " << src_ip << " to " << dest_ip << std::endl;
        return;  // Skip further processing
    }

    // For demonstration, print the packet details
    std::cout << "Packet from " << src_ip << " to " << dest_ip << std::endl;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;

    // Open the default network device for capturing (change "eth0" to your network interface)
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == nullptr) {
        std::cerr << "Couldn't open device: " << errbuf << std::endl;
        return 1;
    }

    // Set a filter to capture only IP packets
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "ip", 0, PCAP_NETMASK_UNKNOWN) == -1 || pcap_setfilter(handle, &fp) == -1) {
        std::cerr << "Couldn't set filter: " << pcap_geterr(handle) << std::endl;
        pcap_close(handle);
        return 1;
    }

    // Start packet capture
    pcap_loop(handle, 0, packetHandler, nullptr);

    pcap_close(handle);
    return 0;
}
/*Explanation
Blocking IP Addresses: The program checks if the source or destination IP address is in the blocked list.
Packet Handling: Captures packets using libpcap and applies the blocking logic in the packetHandler function.
Network Device: Replace "eth0" with the appropriate network interface on your development machine or router.
Step 3: Compile and Run the Program
Save the code to a file, for example, packet_filter.cpp.
Compile the program:
g++ -o packet_filter packet_filter.cpp -lpcap

Run the program with root privileges:
sudo ./packet_filter

Notes
Root Privileges: libpcap requires root privileges to capture packets.
Network Device: Ensure you use the correct network interface.
DNS Resolution: This example doesn't include DNS resolution for blocked domains. You can extend this by integrating a DNS resolver or using additional libraries to handle domain blocking.*/
