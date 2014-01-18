/* isr.c
 *
 *  Created on: 3 Jul 2011
 *      Author: cds
 */

#include<defs.h>
#include<sys/print.h>

#include<sys/ports.h>
#include<sys/kbc.h>
#include <sys/timer.h>
#include<sys/isr.h>
#include<sys/process.h>
#include <sys/gdt.h>
#include <sys/tarfs.h>
#include <sys/fs.h>
/*
bool sflag=true;
task *prev;
task *next;

int no_of_process=2;
*/

void isr_handler0(struct isr_stack_frame *stack) {

        print("DIVIDE BY ZERO ERROR!\n");
        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler1(struct isr_stack_frame *stack) {

        print("isr 1\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler2(struct isr_stack_frame *stack) {

        print("isr 2\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler3(struct isr_stack_frame *stack) {

        print("isr 3\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler4(struct isr_stack_frame *stack) {

        print("isr 4\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler5(struct isr_stack_frame *stack) {

        print("isr 5\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler6(struct isr_stack_frame *stack) {

        print("isr 6\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler7(struct isr_stack_frame *stack) {

        print("isr 7\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler8(struct isr_stack_frame *stack) {

        print("isr 8\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler9(struct isr_stack_frame *stack) {

        print("isr 9\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler10(struct isr_stack_frame *stack) {

        print("isr 10\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler11(struct isr_stack_frame *stack) {

        print("isr 11\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler12(struct isr_stack_frame *stack) {

        print("isr 12\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler13(struct isr_stack_frame *stack) {

        print("isr 13\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
void isr_handler14(struct isr_stack_frame *stack) {

        print("isr 14\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler15(struct isr_stack_frame *stack) {

        print("isr 15\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler16(struct isr_stack_frame *stack) {

        print("isr 16\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler17(struct isr_stack_frame *stack) {

        print("isr 17\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler18(struct isr_stack_frame *stack) {

        print("isr 18\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler19(struct isr_stack_frame *stack) {

        print("isr 19\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler20(struct isr_stack_frame *stack) {

        print("isr 20\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler21(struct isr_stack_frame *stack) {

        print("isr 21\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}


void isr_handler22(struct isr_stack_frame *stack) {

        print("isr 22\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}


void isr_handler23(struct isr_stack_frame *stack) {

        print("isr 23\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}


void isr_handler24(struct isr_stack_frame *stack) {

        print("isr 24\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler25(struct isr_stack_frame *stack) {

        print("isr 25\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler26(struct isr_stack_frame *stack) {

        print("isr 26\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler27(struct isr_stack_frame *stack) {

        print("isr 27\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler28(struct isr_stack_frame *stack) {

        print("isr 28\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler29(struct isr_stack_frame *stack) {

        print("isr 29\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler30(struct isr_stack_frame *stack) {

        print("isr 30\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}

void isr_handler31(struct isr_stack_frame *stack) {

        print("isr 31\n");
//        print("    CS:0x%x\n",stack->cs);
//        print("   RIP:0x%x\n",stack->rip);
      __asm__( "hlt" );
}
/*
void isr_handler32(struct isr_stack_frame *stack) {

        timer_callback();
}*/
void isr_handler33(struct isr_stack_frame *stack) {


        outb(0x20, 0x20);
        kbc_irq();
}
void isr_handler43(struct isr_stack_frame *stack) {

        outb(0x20, 0x20);
        //kbc_irq();
}
void isr_handler128(struct isr_stack_frame *stack) {

    //print("inside isr 128\n");
    uint64_t syscall_no = 0;
    uint64_t buf, third, fourth;
    uint64_t size;
    uint64_t *memptr;
    uint64_t val;
    __asm volatile("movq %%rax, %0;"
            "movq %%rbx, %1;"
            "movq %%rcx, %2;"
            "movq %%rdx, %3;"
            : "=g"(syscall_no),"=g"(buf), "=g"(third), "=g"(fourth)
            :
            :"rax","rsi","rcx"
            );  
 /*   __asm__(
            "movq %%rax, %0;"
            :"=a"(syscall_no)
            :
            :"rax"
            );*/
    //print("syscall %d\n", syscall_no);
    if(syscall_no == 2) {
        //while(*buf != '\0') {
            putc((char)buf);
         //   buf = buf + 1;
       // }
      //  asm("hlt");
    }
    

    else if(syscall_no == 3) {
        __asm__ __volatile__(
                "movq %%rbx, %0;"
                :"=b"(size)
                :
                );
        
        memptr=kmalloc(size);

      //  print("memptr=%x",(uint64_t)memptr);


        __asm__ __volatile__ (
                "movq %0, %%rax;" //load next's stack in rsp
                :   
                :"r"(memptr)
            );  

    }
    else if(syscall_no == 4) {
        //print("inside fork");
        val = fork();
        __asm__ __volatile__ (
                "movq %0, %%rax;" //load next's stack in rsp
                :   
                :"r"(val)
            );  
     //  print("\n{j=%d}", j);
     //  print("\n{j=%d}", j);
       // asm("hlt");

    }
    else if(syscall_no == 5)  
    {
        // exit status has been called with value in %rsi 
        exit_process(buf);        
        //:w
        //asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;                                                                          
    }
    else if(syscall_no == 6)
    {
        val = sleep(buf);
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
    
        __asm__("hlt");
    }
    else if(syscall_no == 7)                                                                                                                         
    {              // j is size  
        void *val = malloc(buf);   // allocate the heap memory with size j 
        //  printf("MALLOC %p\n",val);   
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
    }
    else if(syscall_no == 8) 
    {
        val = get_pid();
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
    }
    else if(syscall_no == 9) 
    {
        val = get_ppid();
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
    }
    else if(syscall_no == 10) 
    {
        //puts((char *)buf);
        val = execvpe((char *)buf, (char **)third, (char **)fourth);
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
    }
    else if(syscall_no == 11) {                       // scanf
        asm ("sti");
        char* buf;
        __asm__ __volatile__(
                                "movq %%rbx, %0;"
                                :"=b"(buf)
                                :
                        );
        scanf(buf);
        //puts(buf);
    }
    else if(syscall_no == 12) {                 // opendir
            uint64_t addrHdr = open_dir((char *)buf);
            __asm__ __volatile__(
                                "movq %0, %%rax;"
                                :
                                :"a" ((uint64_t)addrHdr)
                                :"cc", "memory"
                       );     
    }
    else if(syscall_no == 13) {                 // read dir
       if(buf == 99999)
        {
            hdd_ls();
        }
        else
        {
            read_dir(buf); 
        }

    }
    else if(syscall_no == 14) {                 // open file
        file *fd;
        if((strncmp((char *)buf, "hdd/", 4)) == 0)
        {
            fd = (file *)file_open((char *)buf + 4);
        }
        else
        {
            fd = (file *)open((char *)buf);
        }
        __asm__ __volatile__(
                "movq %0, %%rax;"
                :
                :"a" ((uint64_t)fd)
                :"cc", "memory"
                ); 
    }
    else if(syscall_no == 15) {                 // read file
        int size_read = 0;
        //print("\n-------- %d", ((file *)buf)->is_fs);
        if(((file *)buf)->is_fs == 1)
        {
            size_read = file_read((file *)fourth, (uint32_t)third, (file *)buf);
        }
        else
        {  
            size_read = read_file((file *)buf, (uint32_t)third, fourth);
        }
        __asm__ __volatile__(
                "movq %0, %%rax;"
                :
                :"a" ((uint64_t)size_read)
                :"cc", "memory"
                ); 
    }
    else if(syscall_no == 16) {                 // read file
        //print("%x %x", third, fourth);
        
        int size_read = 0;
        if(((file *)buf)->is_fs == 1)
        {
            size_read = file_seek((file *)buf, (uint32_t)third, fourth);
        }
        else
        {
            print("\nNot supported with tarfs.");
        }

        __asm__ __volatile__(
                "movq %0, %%rax;"
                :
                :"a" ((uint64_t)size_read)
                :"cc", "memory"
                ); 
    }
    else if(syscall_no == 17) {                 // write file
        //print("%x %x", third, fourth);
        int size_read = 0;
        if(((file *)buf)->is_fs == 1)
        {
            size_read = file_write((file *)buf, (char *)third, fourth);
        }
        else
        {
            print("\nNot supported with tarfs.");
        }

        
        __asm__ __volatile__(
                "movq %0, %%rax;"
                :
                :"a" ((uint64_t)size_read)
                :"cc", "memory"
                ); 
    } 
    else if(syscall_no == 18) //file_write
    {
        val = waitpid(buf,third);
        asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;
        //puts((char *)buf);
    }
    else if(syscall_no == 21) //ps
    {
        dp();
        //asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;     
    }
    else if(syscall_no == 22) //ps
    {
        asm("sti");
        //print("sleep %d", buf);
        sleep_shell(buf);
        //asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;     
    }
    else if(syscall_no == 25) //ps
    {
        kshutdown();
        //asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;     
    }
    else if(syscall_no == 26) //ps
    {

        putc_color((char)buf);
        //asm volatile("movq %0, %%rax":: "b"(val)); //store return valueo;     
    }


}
