import matplotlib
matplotlib.use('TkAgg') # 強制使用 TkInter 顯示視窗
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random
import copy

# --- 1. 產生隨機資料 ---
n_elements = 100
original_data = list(range(1, n_elements + 1))
random.shuffle(original_data)

# --- 2. 排序演算法 (Generator 版本，每次交換後 yield) ---

def bubble_sort(data):
    n = len(data)
    for i in range(n):
        for j in range(0, n - i - 1):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
                yield data

def insertion_sort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i - 1
        while j >= 0 and key < data[j]:
            data[j + 1] = data[j]
            j -= 1
            yield data
        data[j + 1] = key
        yield data

def merge_sort(data, start, end):
    if end - start > 1:
        mid = (start + end) // 2
        yield from merge_sort(data, start, mid)
        yield from merge_sort(data, mid, end)
        
        # Merge process
        left = data[start:mid]
        right = data[mid:end]
        i = j = 0
        for k in range(start, end):
            if i < len(left) and (j >= len(right) or left[i] <= right[j]):
                data[k] = left[i]
                i += 1
            else:
                data[k] = right[j]
                j += 1
            yield data

def quick_sort(data, start, end):
    if start < end:
        pivot = data[end]
        p_index = start
        for i in range(start, end):
            if data[i] <= pivot:
                data[i], data[p_index] = data[p_index], data[i]
                p_index += 1
                yield data
        data[p_index], data[end] = data[end], data[p_index]
        yield data
        yield from quick_sort(data, start, p_index - 1)
        yield from quick_sort(data, p_index + 1, end)

def heap_sort(data):
    n = len(data)
    def heapify(n, i):
        largest = i
        l, r = 2 * i + 1, 2 * i + 2
        if l < n and data[i] < data[l]: largest = l
        if r < n and data[largest] < data[r]: largest = r
        if largest != i:
            data[i], data[largest] = data[largest], data[i]
            yield data
            yield from heapify(n, largest)

    for i in range(n // 2 - 1, -1, -1):
        yield from heapify(n, i)
    for i in range(n - 1, 0, -1):
        data[i], data[0] = data[0], data[i]
        yield data
        yield from heapify(i, 0)

def counting_sort(data):
    max_val = max(data)
    count = [0] * (max_val + 1)
    for x in data: count[x] += 1
    i = 0
    for val, c in enumerate(count):
        for _ in range(c):
            data[i] = val
            i += 1
            yield data

def radix_sort(data):
    max_val = max(data)
    exp = 1
    while max_val // exp > 0:
        # Simplified counting sort for radix
        output = [0] * len(data)
        count = [0] * 10
        for i in range(len(data)):
            index = (data[i] // exp) % 10
            count[index] += 1
        for i in range(1, 10): count[i] += count[i-1]
        i = len(data) - 1
        while i >= 0:
            index = (data[i] // exp) % 10
            output[count[index] - 1] = data[i]
            count[index] -= 1
            i -= 1
        for i in range(len(data)):
            data[i] = output[i]
            yield data
        exp *= 10

# --- 3. 初始化繪圖視窗 ---
fig, axes = plt.subplots(2, 4, figsize=(16, 8))
fig.suptitle('Sorting Algorithms Speed Comparison')
axes = axes.flatten()

# 演算法清單與名稱
algo_names = ["Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort", 
              "Heap Sort", "Counting Sort", "Radix Sort"]
algos = [
    bubble_sort(copy.deepcopy(original_data)),
    insertion_sort(copy.deepcopy(original_data)),
    merge_sort(copy.deepcopy(original_data), 0, n_elements),
    quick_sort(copy.deepcopy(original_data), 0, n_elements - 1),
    heap_sort(copy.deepcopy(original_data)),
    counting_sort(copy.deepcopy(original_data)),
    radix_sort(copy.deepcopy(original_data))
]

# 建立 7 個 Bar 圖
bars = []
for i in range(7):
    ax = axes[i]
    ax.set_title(algo_names[i])
    bar = ax.bar(range(len(original_data)), original_data, align='edge', color='skyblue')
    ax.set_xlim(0, n_elements)
    ax.set_ylim(0, n_elements + 10)
    ax.axis('off') # 隱藏軸標籤增加視覺美感
    bars.append(bar)

axes[7].axis('off') # 第 8 個框框留空

# --- 4. 動畫更新函式 ---
def update(frame):
    # 同步推動 7 個 Generator
    for i, algo in enumerate(algos):
        try:
            # 取得該演算法當下的資料狀態
            current_data = next(algo)
            # 更新對應的 Bar 高度
            for rect, val in zip(bars[i], current_data):
                rect.set_height(val)
        except StopIteration:
            # 如果該排序已完成，將其顏色改為綠色
            for rect in bars[i]:
                rect.set_color('green')
    return [b for bar_set in bars for b in bar_set]

# 執行動畫
ani = animation.FuncAnimation(fig, update, frames=2000, interval=1, repeat=False, blit=True)

plt.tight_layout()
plt.show()
