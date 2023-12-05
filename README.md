# 5600-VM
```zsh
$./TLB -h
Usage: ./TLB [OPTIONS]...

Supported options:
-s,    --size = PAGE_SIZE
	size of the page
-l1,   --l1tlb = L1_TLB_ENTRY_CNT
	l1 TLB entry count
-l2,   --l2tlb = L2_TLB_ENTRY_CNT
	l2 TLB entry count
-l1t,  --l1tlbTime = L1_ACCESS_TIME
	l1 TLB access time
-l2t,  --l2tlbTime = L2_ACCESS_TIME
	l2 TLB access time
-l1p,  --l1tlbPolicy = L1_TLB_POLICY
	l1 TLB policy (FIFO, LRU, RAND)
-l2p,  --l2tlbPolicy = L2_TLB_POLICY
	l2 TLB policy (FIFO, LRU, RAND)
-w,    --workload = WORKLOAD
	path to workload file, workload is represented by list of page to be accessed

```
