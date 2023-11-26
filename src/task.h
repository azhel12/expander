#ifndef TASK_H_
#define TASK_H_

#include <native.h>

#include <cstddef>

template<typename _derived, unsigned _stackSizeBytes, unsigned _priority = 0>
class TaskBase
{
    static_assert(_stackSizeBytes % sizeof(bgrt_stack_t) == 0);
    static constexpr auto _stackSize = _stackSizeBytes / sizeof(bgrt_stack_t);
protected:
    static bgrt_proc_t _handle;
    static bgrt_stack_t _stack[_stackSize];

public:
    static void Init() {
        bgrt_proc_init(&_handle, _derived::Entry, 0, 0, nullptr, &_stack[_stackSize-1], _priority, 1, 0);
    }

    static void Run() {
        bgrt_proc_run(&_handle);
    }

    static void InitPrivilege() {
        bgrt_priv_proc_init(&_handle, _derived::Entry, 0, 0, nullptr, &_stack[_stackSize-1], _priority, 1, 0);
    }

    static void RunPrivilege() {
        bgrt_priv_proc_run(&_handle);
    }
};
template<typename _derived, unsigned _stackSizeBytes, unsigned _priority>
inline bgrt_proc_t TaskBase<_derived, _stackSizeBytes, _priority>::_handle;
template<typename _derived, unsigned _stackSizeBytes, unsigned _priority>
inline bgrt_stack_t TaskBase<_derived, _stackSizeBytes, _priority>::_stack[TaskBase<_derived, _stackSizeBytes, _priority>::_stackSize];

namespace Private {
    template<auto _entry>
    struct EntryWrapper
    {
        static __attribute__((always_inline)) void Entry(void* arg)
        {
            _entry(arg);
        }
    };
}

template<auto _entry, unsigned _stackSizeBytes, unsigned _priority = 0>
using SimpleTask = TaskBase<Private::EntryWrapper<_entry>, _stackSizeBytes, _priority>;

#endif