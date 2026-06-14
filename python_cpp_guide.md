# Python & C++ 執行與開發指南

本指南整理了在 `/home/arthur/Algorithm` 工作區中，建立/啟動 Python 虛擬環境以及編譯與執行 Python 和 C++ 程式碼的常用指令。

---

## 一、 Python 虛擬環境 (Virtual Environment)

虛擬環境可以將專案所需的 Python 套件獨立安裝，避免與系統全域套件衝突。

### 1. 建立虛擬環境
如果您尚未建立虛擬環境，請在專案根目錄下執行以下指令建立名為 `.venv` 的資料夾：
```bash
python3 -m venv .venv
```

### 2. 啟動虛擬環境 (Linux / macOS)
在執行任何 Python 程式或安裝套件之前，請先啟動虛擬環境：
```bash
source .venv/bin/activate
```
* **啟動成功標記**：啟動後，終端機提示字元前方會顯示虛擬環境名稱，例如 `(.venv) user@hostname:...$`。
* *註：若使用 `fish` 殼層，請執行 `source .venv/bin/activate.fish`；`csh`/`tcsh` 請執行 `source .venv/bin/activate.csh`。*

### 3. 安裝依賴套件
啟動虛擬環境後，即可使用 `pip` 安裝專案所需的套件。例如安裝 `matplotlib`：
```bash
pip install matplotlib
```

### 4. 關閉虛擬環境
開發結束後，若想退出虛擬環境，直接輸入：
```bash
deactivate
```

---

## 二、 執行 Python 腳本 (Python Scripts)

執行 Python 腳本時，需特別注意該腳本是否需要讀取相對路徑下的測資檔案。

### 情況 A：無外部套件依賴，但需讀取同目錄測資 (例如 [graph_method.py](file:///home/arthur/Algorithm/visualization/graph_method.py))
由於此腳本會讀取同目錄下的 [input.txt](file:///home/arthur/Algorithm/visualization/input.txt)，執行時必須先切換至該目錄：
```bash
cd /home/arthur/Algorithm/visualization
python3 graph_method.py
```

### 情況 B：有外部套件依賴且有圖形介面 (例如 [sort_visualization.py](file:///home/arthur/Algorithm/visualization/sort_visualization.py))
此腳本需要 `matplotlib`，因此必須先啟動虛擬環境再執行：
```bash
cd /home/arthur/Algorithm
source .venv/bin/activate
python3 visualization/sort_visualization.py
```

---

## 三、 編譯與執行 C++ 程式碼 (C++ Programs)

C++ 是編譯型語言，需要先透過編譯器（如 `g++`）將原始碼編譯為二進位執行檔，然後才能執行。

### 1. 編譯 C++ 原始碼
使用 `g++` 編譯，並用 `-o` 指定輸出執行檔的名稱。
例如編譯根目錄底下的 [try.cpp](file:///home/arthur/Algorithm/try.cpp)：
```bash
g++ -o try try.cpp
```

### 2. 執行編譯後的執行檔
```bash
./try
```

### 3. 編譯並執行子資料夾中的檔案
例如編譯並執行位於 `sort/` 下的 [bubble_sort.cpp](file:///home/arthur/Algorithm/sort/bubble_sort.cpp)：
```bash
g++ -o bubble_sort sort/bubble_sort.cpp
./bubble_sort
```
