Packet sniffing is a technique used to monitor network traffic. It involves capturing and analyzing packets of data as they travel across a network. Here is a basic C code for packet sniffing:

```
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Open the network interface for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        exit(1);
    }

    // Get the network address and mask for the interface
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network address and mask: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the capture handle
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print the packet data
    printf("Packet captured: %d bytes\n", header->len);
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", pkt_data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
```

This code uses the `pcap` library to capture packets on the network interface `eth0`. It compiles a filter expression to only capture IP packets, and then loops indefinitely, calling the `packet_handler` function for each captured packet. The `packet_handler` function simply prints the packet data in hexadecimal format.
