#ifndef BGRT_CONFIG_H
/* Example config file */
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

#ifndef __ASSEMBLER__

#define BGRT_SC_TBL(a) const bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) a

#ifndef NOP
#define NOP() __asm__ __volatile__ ("nop":::)
#endif

typedef unsigned long bgrt_stack_t;

/**================================================================*/
/**               Edit this part carefully!!!                   */
/**================================================================*/

/* Max priority levels are defined by bgrt_map_t,*/
/* you must specify BGRT_BITS_IN_INDEX_T to show*/
/* how many levels you actually are going to use.*/
/* data types*/
typedef unsigned long bgrt_map_t;
#define BGRT_BITS_IN_INDEX_T (4)
#define BGRT_CONFIG_USER_SEARCH(map) (__builtin_ctzl(map))

/* Even if bgrt_map_t is unsigned long long,*/
/* there will be only 64 priority levels available,*/
/* so unsigned char is always enough.*/
typedef unsigned char bgrt_prio_t;

/* unsigned char is enough.*/
typedef unsigned char bgrt_flag_t;

/* unsigned char is enough.*/
typedef unsigned char bgrt_st_t;

#define BGRT_CONFIG_CNT_MAX (0xffffffff)
typedef unsigned long bgrt_cnt_t;

typedef volatile unsigned long bgrt_tmr_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_bool_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_syscall_t;
/**===============================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/**===============================================================*/
#define BGRT_CONFIG_HARD_RT
/**===============================================================*/
/**     Project specific stuff, you are welcome to edit it!!!*/
/**===============================================================*/
#define BGRT_CONFIG_TEST  /*This is test project*/.

/*These macros needed to interface cstartup code.*/
#define BGRT_SYSTEM_TIMER_ISR 	    SysTick_Handler
#define BGRT_SYSCALL_ISR			PendSV_Handler

#define BGRT_CONFIG_PRIO_BITS       2  /*Used upper priority bits*/
#define BGRT_CONFIG_SCHED_PRIO 		3 /*Scheduler priority*/

/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

extern void kernel_preemt_hook(void);
#define BGRT_KERNEL_PREEMPT() kernel_preemt_hook()

#endif /*__ASSEMBLER__*/
#endif /*BGRT_CONFIG_H*/
