#undef TRACE_SYSTEM
#define TRACE_SYSTEM modem_if

#if !defined(_TRACE_MODEM_IF_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MODEM_IF_H

#include <linux/tracepoint.h>

TRACE_EVENT(mif_event,

	TP_PROTO(struct sk_buff *skb, unsigned size, char const *function),

	TP_ARGS(skb, size, function),

	TP_STRUCT__entry(
		__field(void *, skbaddr)
		__field(unsigned, size)
		__array(char, function, 32)
	),

	TP_fast_assign(
		__entry->skbaddr = skb;
		__entry->size = size;
		memcpy(__entry->function, function, 32);
	),

	TP_printk("mif: skbaddr=%p, size=%d, function=%s",
		__entry->skbaddr,
		__entry->size,
		__entry->function)
);
#endif

/* This part must be outside protection */
#include <trace/define_trace.h>

