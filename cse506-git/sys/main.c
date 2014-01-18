#include <defs.h>
#include <sys/gdt.h>
#include <sys/print.h>
#include <sys/pmap.h>
#include <sys/idt.h>
#include <sys/isr.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <sys/tarfs.h>
#include <sys/ahci.h>
#include <sys/fs.h>
#include <string.h>

#define INITIAL_STACK_SIZE 4096
char stack[INITIAL_STACK_SIZE];
uint32_t* loader_stack;
extern char kernmem, physbase;

extern pml4e_t *boot_pml4e;
extern physaddr_t boot_cr3;


//  struct task_struct pcb2;
uint64_t *pages_for_ahci_start;
uint64_t *pages_for_ahci_start_virtual;

uint64_t bar5;
void start(uint32_t* modulep, void* physbase, void* physfree)
{

    mm_init(modulep,physbase,physfree);

    pages_for_ahci_start_virtual = (uint64_t *)kmalloc_ahci(32*4096);
    pages_for_ahci_start = (uint64_t *)PADDR(pages_for_ahci_start_virtual);
    pages_for_ahci_start = (uint64_t *)(((uint64_t)pages_for_ahci_start+0x0FFF) & ~ 0x0FFF);
    pages_for_ahci_start_virtual = (uint64_t *)(((uint64_t)pages_for_ahci_start_virtual+0x0FFF) & ~ 0x0FFF);
    //memset((void *)pages_for_ahci_start_virtual, 0, 32*4096); 
    //print("\n vir %x %x", pages_for_ahci_start_virtual, pages_for_ahci_start_virtual + 32*4096);
    //print("\n phy %x %x", pages_for_ahci_start, pages_for_ahci_start + 32*4096);

    reload_gdt();
    reload_idt();
    load_irq();
    setup_tss();
    print_line(30, 0, "Welcome To SBUnix");
    /********************************* KERNEL CREATION ********************************/
    struct task_struct *pcb0 = (struct task_struct *)kmalloc(sizeof(struct task_struct));  //kernel 
    pcb0->pml4e =(uint64_t)boot_pml4e;  // kernel's page table   
    pcb0->cr3 = boot_cr3; // kernel's page table   
    pcb0->pid = 0;  // I'm kernel init process  so pid 0  
    pcb0->stack =(uint64_t *)stack; //my stack is already created by prof :)  
    process_count = 0; //at this point we don't have any other process in ready_queue so go ahead and create one and update this 
    sleeping_process_count = 0; // at this point no body is sleeping 
    // initialize processes queue  
    int i=0;
    for(i=0;i<100;i++)  {   
        zombie_queue[i] = 0;    // no process is zombie 
    }

    ready_queue[0] =(uint64_t )pcb0;  //kernel 

    char fname1[]="bin/sh";
   char fname2[]="bin/hello";
    char fname3[]="bin/hello1";

    struct task_struct *pcb1 = malloc_pcb(fname1);
    struct task_struct *pcb2 = malloc_pcb(fname2);
    struct task_struct *pcb3 = malloc_pcb(fname3);

    print("\nThis print due to unused variable - %p - %p - %p\n",pcb1,pcb2,pcb3);

    tarfs_init();
    probe_port((HBA_MEM *)(0xFFFFFFFF00000000+(uintptr_t)bar5)); 
    inialize_sata_table();
   
    /*char test[1200];
    int k = 0;
    for(k=0 ;k<1200; k++)
    {
        if(k<512)
            test[k] = 'x';
        else if (k >= 512 && k <= 700 )
            test[k] = 'y';
        else if (k > 700 && k <= 1000 )
            test[k] = 'z';
        else if (k > 1000 && k <= 1500 )
            test[k] = 'w';
    }   
   */
    //file * fd = file_open("test33333.txt");
    //file_write(fd, test, 1500);
    
  /*  file * fd = file_open("test33333.txt");
    char test1[1000];
    file_seek(fd, 500, SEEK_END);
    file_seek(fd, 100, SEEK_CUR);
    file_seek(fd, 512, SEEK_SET);
    print(" \n offset %d \n",fd->offset);
    file_read(test1, 400, fd);
    puts(test1);*/
//    file_close(fd);
    asm volatile("mov $0x2b,%ax");
    asm volatile("ltr %ax");
    init_timer();
    __asm__("sti"); 
    while(1);
}

void boot(void)
{
    // note: function changes rsp, local stack variables can't be practically used
    register char *temp1, *temp2;
    __asm__(
            "movq %%rsp, %0;"
            "movq %1, %%rsp;"
            :"=g"(loader_stack)
            :"r"(&stack[INITIAL_STACK_SIZE])
           );
    start(
            (uint32_t*)((char*)(uint64_t)loader_stack[3] + (uint64_t)&kernmem - (uint64_t)&physbase),
            &physbase,
            (void*)(uint64_t)loader_stack[4]
         );
    for(
            temp1 = "!!!!! start() returned !!!!!", temp2 = (char*)0xb8000;
            *temp1;
            temp1 += 1, temp2 += 2
       ) *temp2 = *temp1;
    while(1);
}
