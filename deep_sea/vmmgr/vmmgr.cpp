#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include "lru.cpp"

using namespace std;

#define PAGE_SIZE 256
#define PAGE_TABLE_ENTRIES 256

#define FRAME_SIZE 256
#define NUM_FRAMES 256

#define TLB_ENTRIES 16

// int page_table[PAGE_TABLE_ENTRIES] = {-1};
// int tlb[TLB_ENTRIES] = {-1};
// char physical_memory[FRAME_SIZE * NUM_FRAMES];

// float tlb_lookup_count;
// float tlb_hit;

// float page_lookup_count;
// float page_fault;

//need to separate physical memory and backing store
class VMMGR { 
    private: 
        int references = 0;
        int page_faults = 0;
        int tlb_hits = 0;
        int available_page_frame = 0;
        string backing_store;

        LRUCache *tlb;
        int page_table[PAGE_TABLE_ENTRIES]; 
        char physical_memory[FRAME_SIZE * NUM_FRAMES];

        inline int extract_offset(int addr);
        inline int extract_page_number(int addr);
        int consult_page_table(int page_number);
        int pull_from_backing_store(int page_number);
        int consult(int page_number);

    public:
        VMMGR(string backing_store);
        // ~VMMGR();
        int addr_translate(int logic_addr); 
        char access(int logic_addr);
        void print_stats(); 
};

VMMGR::VMMGR(string backing_store) {
    this->backing_store = backing_store;
    tlb = new LRUCache(TLB_ENTRIES);

    for(int i = 0; i < PAGE_TABLE_ENTRIES; i ++) {
        page_table[i] = -1;
    }

    for(int i = 0; i < PAGE_TABLE_ENTRIES; i ++) {
        page_table[i] = -1;
    }
}

// VMMGR::~VMMGR() {
//     delete tlb;
// }

inline int VMMGR::extract_offset(int addr) {
    return addr & 0xFF;
}

inline int VMMGR::extract_page_number(int addr) {
   return (addr >> 8) & 0xFF; 
}

int VMMGR::consult_page_table(int page_number) {
    cout << "consulting page table" << endl;
    int frame_number;
    if (page_table[page_number] == -1) {
        cout << "page table failed" << endl;
        frame_number = pull_from_backing_store(page_number);
        page_table[page_number] = frame_number;
        page_faults ++;
    } else {
        frame_number = page_table[page_number];
    }

    tlb->put(page_number, frame_number);

    return frame_number;
}

int VMMGR::pull_from_backing_store(int page_number) {    
    int frame_number;
    // ifstream search{ "BACKING_STORE.bin" };

    // if (!search) { 
    //     cerr << "invalid backing store" << endl; 
    //     exit (EXIT_FAILURE);
    // } else {
    cout << "available page frame: " << available_page_frame << endl;

    for(int i = 0; i < 256; i ++) {
        physical_memory[available_page_frame*PAGE_SIZE + i] = '1';
    } 

    // FILE *fp;
    // fp = fopen("BACKING_STORE.bin", "r");
    // fseek(fp, page_number*PAGE_SIZE, 0);
    // fread(&physical_memory[available_page_frame*PAGE_SIZE], 1, 256, fp);
    // fclose(fp);

    for(int i = 0; i < 256; i ++) {
        cout << physical_memory[available_page_frame*PAGE_SIZE + i] << ",";
    } cout << endl;

    cout << physical_memory[20] << endl;

    frame_number = available_page_frame;
    available_page_frame ++;

    return frame_number;
}

int VMMGR::consult(int page_number) {
    int frame_number = tlb->get(page_number);
    cout << "consulting tlb" << endl;
    if (frame_number == -1) {
        frame_number = consult_page_table(page_number);
        cout << "failed" << endl;
    } else {
        tlb_hits ++;
        cout << "success" << endl;
    }
    references ++;
    return 0; 
}

int VMMGR::addr_translate(int logic_addr) {
    cout << endl;
    int page_number = extract_page_number(logic_addr);
    cout << "page number: " << page_number << endl;

    int offset = extract_offset(logic_addr);
    cout << "offset: " << offset << endl;

    int frame_number = consult_page_table(page_number);
    cout << "frame number: " << frame_number << endl;

    int physical_address = (frame_number*PAGE_SIZE) + offset;
    cout << "physical address: " << physical_address << endl;

    cout << physical_memory[physical_address] << endl;

    for(int i = 0; i < 255; i ++) {
        cout << page_table[i];
    } cout << endl;

    cout << endl;

    return physical_address;
}

char VMMGR::access(int logic_addr) {
    int physical_addr = addr_translate(logic_addr);
    cout << "physical address: " << physical_addr << endl;
    cout << physical_memory[physical_addr] << endl;
    return physical_memory[physical_addr];
}


void VMMGR::print_stats() {
    cout << "faults" << page_faults << endl;
}

int main (int argc, char **argv) {
    if (argc != 2) {
        // cerr << "requires address file: './a.out <address file>' " << endl;
        exit (EXIT_FAILURE);
    }

    string address_file = argv[1];
    // cout << address_file << endl;

    // ifstream search{ address_file };
    // search.seekg(3); char c;
    // search.get(c);
    // search.get(c);
    // search.get(c);
    // search.get(c);
    // search.get(c);

    // cout << c << endl;

    VMMGR my_vmmgr = VMMGR("BACKING_STORE.bin");

    ifstream search{address_file};
    string curr_line; int count = 50;
    while(getline(search, curr_line) && count > 0) {
        my_vmmgr.access(stoi(curr_line));        
        count --;
    }

    my_vmmgr.print_stats();

    return 0;
}
