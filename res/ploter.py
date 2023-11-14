import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# x = np.arange(0,len(df['date'])*2,2)
width=0.15
x = np.arange(3)
x1 = x-width/2-width
x2 = x-width/2
x3 = x+width/2
x4 = x+width/2+width

y1 = [76.92, 76.92, 69.23]
y2 = [69.23, 61.54, 69.23]
y3 = [61.54, 61.54, 69.23]
y4 = [61.54, 61.54, 58]

plt.ylim(50, 100)
# 绘制分组柱状图

plt.bar(x1,y1,width=0.15,label='0.25',edgecolor='k',zorder=2)
plt.bar(x2,y2,width=0.15,label='0.50',edgecolor='k',zorder=2)
plt.bar(x3,y3,width=0.15,label='0.75',edgecolor='k',zorder=2)
plt.bar(x4,y4,width=0.15,label='1',edgecolor='k',zorder=2)

# 添加x,y轴名称、图例和网格线
plt.xlabel('Replacement Policy', fontsize=11)
plt.ylabel('TLB miss rate (%)', fontsize=11)
plt.legend(frameon=False)
plt.grid(ls='--',alpha=0.8)

# 修改x刻度标签为对应日期
plt.xticks(x,['LRU', 'FIFO', 'RAND'],fontsize=10)
plt.tick_params(axis='x',length=0)

plt.tight_layout()
# plt.savefig('bar2.png',dpi=600)
plt.show()