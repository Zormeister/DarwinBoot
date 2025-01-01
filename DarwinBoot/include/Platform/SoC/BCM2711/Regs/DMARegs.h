// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

#pragma once

#define rDMA_CNTL_STAT 0x0
#define DMA_CNTL_STAT__ACTIVE_MASK (1 << 0)
#define DMA_CNTL_STAT__ACTIVE_SHIFT 0
#define DMA_CNTL_STAT__END_MASK (1 << 1)
#define DMA_CNTL_STAT__END_SHIFT 1
#define DMA_CNTL_STAT__IRQ_STATUS_MASK (1 << 2)
#define DMA_CNTL_STAT__IRQ_STATUS_SHIFT 2
#define DMA_CNTL_STAT__DATA_REQUEST_MASK (1 << 3)
#define DMA_CNTL_STAT__DATA_REQUEST_SHIFT 3
#define DMA_CNTL_STAT__PAUSED_MASK (1 << 4)
#define DMA_CNTL_STAT__PAUSED_SHIFT 4
#define DMA_CNTL_STAT__DREQ_STOPS_DMA_MASK (1 << 5)
#define DMA_CNTL_STAT__DREQ_STOPS_DMA_SHIFT 5
#define DMA_CNTL_STAT__WAITING_FOR_LAST_WRITE_MASK (1 << 6)
#define DMA_CNTL_STAT__WAITING_FOR_LAST_WRITE_SHIFT 6
/* Bit 7 is reserved. */
#define DMA_CNTL_STAT__ERROR_MASK (1 << 7)
#define DMA_CNTL_STAT__ERROR_SHIFT 7
/* Bits 9 to 15 are reserved. */
#define DMA_CNTL_STAT__PRIORITY_MASK (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19)
#define DMA_CNTL_STAT__PRIORITY_SHIFT 16
#define DMA_CNTL_STAT__PANIC_PRIORITY_MASK (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19)
#define DMA_CNTL_STAT__PANIC_PRIORITY_SHIFT 16
/* Bits 24 to 27 are reserved. */
#define DMA_CNTL_STAT__WAIT_FOR_OUTSTANDING_WRITES_MASK (1 << 28)
#define DMA_CNTL_STAT__WAIT_FOR_OUTSTANDING_WRITES_SHIFT 28
#define DMA_CNTL_STAT__DISABLE_DEBUG_MASK (1 << 29)
#define DMA_CNTL_STAT__DISABLE_DEBUG_SHIFT 29
#define DMA_CNTL_STAT__ABORT_DMA_MASK (1 << 30)
#define DMA_CNTL_STAT__ABORT_DMA_SHIFT 30
#define DMA_CNTL_STAT__RESET_MASK (1 << 31)
#define DMA_CNTL_STAT__RESET_SHIFT 31

/* Bits 0 to 31 are the whole address to the Control Block */
#define rDMA_CNTL_BLK_ADDR 0x4

#define rDMA_TRANSFER_INFO 0x8
#define rDMA_SOURCE_ADDR 0xC
#define rDMA_DEST_ADDR 0x10
#define rDMA_TRANSFER_LEN 0x14
#define rDMA_STRIDE 0x18
#define rDMA_DEBUG 0x20

/* The driver during runtime will map out the DMA engines to channels, that subsystem is yet to be setup. */
#define rDMA_IRQ_STATUS 0xFE0
#define rDMA_CHAN_ENABLE 0xFF0