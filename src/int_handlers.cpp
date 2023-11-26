
#include <zhele/dma.h>
#include "rpc.h"

extern "C" {
    void DMA1_Channel2_3_IRQHandler()
    {
        Zhele::Dma1Channel2::IrqHandler();
        Zhele::Dma1Channel3::IrqHandler();
    }
}