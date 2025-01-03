# HomeKit 門鎖控制系統專案計畫
## 專案概述
此專案旨在使用Arduino和ESP32 NodeMCU來開發一個可以通過iPhone的家庭App (HomeKit) 控制的門鎖系統。

## 1. 專案流程 

### 階段一：規劃與設計
- 確定專案需求和功能。
- 設計系統架構和接線圖。
- 選擇合適的硬體和軟體工具。

### 階段二：硬體組裝
- 購買所有必要的硬體。
- 根據設計圖進行硬體組裝。
- 安裝RFID讀卡器和按鈕。

### 階段三：軟體開發
- 編程ESP32以連接到HomeKit。
- 編寫用於RFID和按鈕的控制腳本。
- 測試軟體和硬體的整合。

### 階段四：測試與調整
- 在實際環境中測試系統。
- 調整和解決出現的任何問題。
- 最終確認系統運行穩定。

### 階段五：部署與監控
- 安裝於實際使用環境。
- 監控系統性能並做持續的維護。

## 2. 概念圖
![ESP32.drawio](https://hackmd.io/_uploads/SyOiPR4DC.png)
## 3. 流程圖
![流程圖.drawio](https://hackmd.io/_uploads/rygrQJBv0.png)

### 想法
#### 系統Code
#### 硬體整合
#### 遠程
 1. 感應經過跳通知 mac address 識別
 2. 人臉傳送畫面辨認 遠端開門
:::danger
情境設定:
- 家庭裝置(限用Wifi環境)
- 採用HomeKit家庭功能開關門鎖
:::
## 4. 需要軟硬體

###  說明

以下列表包含了完成專案所需的所有核心零件及接線材料。根據具體需求，可能還需要其他工具或材料，如焊接設備、線路剪等。

### 零件明細

- [ ] **ESP32 DevKitC 開發板（或兼容板）** - 數量: 1
- [ ] [**19 針單排母座** - 數量: 2](https://shopee.tw/%E3%80%90%E7%A5%A5%E6%98%8C%E9%9B%BB%E5%AD%90%E3%80%912.54-3P~40P-%E5%96%AE%E6%8E%92%E6%8E%92%E6%AF%8D-%E6%8E%92%E9%87%9D-%E6%AF%8D%E5%BA%A7-%E6%8E%92%E9%87%9D%E6%AF%8D%E5%BA%A7-%E6%8F%92%E9%87%9D%E6%AF%8D%E5%BA%A7-PCB-2.54mm-%E9%96%93%E8%B7%9D2.54-i.27742636.23045016864?sp_atk=98a2cf91-4ad4-4f7d-9ffb-989d7e5037bb&xptdk=98a2cf91-4ad4-4f7d-9ffb-989d7e5037bb&is_from_login=true)
- [ ] [**12V 電門鎖** - 數量: 1](https://shopee.tw/%E3%80%90AI%E9%9B%BB%E5%AD%90%E3%80%91*12V%E5%B0%8F%E5%9E%8B%E9%9B%BB%E6%8E%A7%E9%8E%96-%E9%9B%BB%E7%A3%81%E9%96%A5%E9%8E%96%E9%9B%BB%E5%AD%90%E9%96%80%E9%8E%96%E5%B0%8F%E9%9B%BB%E6%8F%92%E9%8E%96%E6%A9%9F%E6%AB%83%E9%8E%96-%E6%8A%BD%E5%B1%9C%E5%B0%8F%E9%9B%BB%E9%8E%96-i.26861496.13239819041?sp_atk=c4a51093-3184-4973-9812-5f1d08d97c4e&xptdk=c4a51093-3184-4973-9812-5f1d08d97c4e)
- [ ] [**TIP120 電晶體** - 數量: 1](https://shopee.tw/%E3%80%90UCI%E9%9B%BB%E5%AD%90%E3%80%91(C-4-10)-%E5%85%A8%E6%96%B0%E5%8E%9F%E8%A3%9D-TIP120-%E9%81%94%E6%9E%97%E9%A0%93%E4%BA%92%E8%A3%9C%E7%9F%BD%E5%8A%9F%E7%8E%87%E9%9B%BB%E6%99%B6%E9%AB%94-%E7%9B%B4%E6%8F%92-TO-220-i.2305548.1602082642?sp_atk=a7b3036d-41b1-46fd-99e6-3207d9d6e428&xptdk=a7b3036d-41b1-46fd-99e6-3207d9d6e428)
- [ ] **1k Ohm 電阻** - 數量: 1
- [ ] [**1N4001 二極管** - 數量: 1](https://shopee.tw/%E3%80%90AI%E9%9B%BB%E5%AD%90%E3%80%91*%E4%BA%8C%E6%A5%B5%E7%AE%A11N4001-IN4001-%E7%9B%B4%E6%8F%92%E4%BA%8C%E6%A5%B5%E7%AE%A110%E5%8F%AA-i.26861496.8347589722?sp_atk=c189663f-ee5a-48af-8042-2f9b0b69714b&xptdk=c189663f-ee5a-48af-8042-2f9b0b69714b)
- [ ] **2.1/5.5mm DC 電源插座** - 數量: 1
- [ ] **綠色 LED** - 數量: 1
- [ ]  **220 Ohms 電阻** - 數量: 1
- [ ] [**16mm 帶 12V LED 按鈕（可選購帶面板門鐘掣）** - 數量: 1](https://shopee.tw/%F0%9F%92%95%E5%8F%B0%E7%81%A3%E5%87%BA%E8%B2%A8%F0%9F%92%95%E9%87%91%E5%B1%AC%E6%8C%89%E9%88%95%E9%96%8B%E9%97%9C-12-16-19-22MM-%E5%B8%A6%E7%81%AFLED-%E5%95%9F%E5%8B%95%E9%9B%BB%E6%BA%90-%E9%98%B2%E6%B0%B4-%E6%8C%89%E5%A3%93%E9%96%8B%E9%97%9C-3V-6V-12V-24V-i.27303306.25764831159?publish_id=&sp_atk=87272c89-f67f-489c-8394-d838b833562c&xptdk=87272c89-f67f-489c-8394-d838b833562c)
- [ ] **2 針 2.54mm JST 迷你直針插和座（電門鎖用）** - 數量: 1
- [ ] **4 針 2.54mm JST 迷你直針插和座（帶 LED 按鈕用）** - 數量: 1
- [ ] **1/2 麵包板** - 數量: 1
- [ ] **適量杜邦線** - 數量: 若干
- [ ] [**繼電器**(將esp32 電壓提升至12v)](https://shopee.tw/%E3%80%90AI%E9%9B%BB%E5%AD%90%E3%80%91*(12-1)1%E8%B7%AF%E7%B9%BC%E9%9B%BB%E5%99%A8%E6%A8%A1%E7%B5%84%E5%B8%B6%E5%85%89%E8%80%A6%E9%9A%94%E9%9B%A2-%E9%AB%98%E9%9B%BB%E5%B9%B3%E4%BD%8E%E9%9B%BB%E5%B9%B3%E9%80%9A%E7%94%A8%E6%9D%BF-5V-12V%E7%89%88%E6%9C%AC%E9%83%BD%E6%9C%89-i.26861496.830727299?sp_atk=4796a54e-dc02-4499-9a8b-796521426ee1&xptdk=4796a54e-dc02-4499-9a8b-796521426ee1)
### 需要軟體

- Arduino IDE（用於編寫和上傳ESP32的程式碼）
- HomeKit軟體開發套件（用於將設備接入HomeKit生態）
- RFID庫（用於讀取RFID標籤）
- Apple Developer Program賬戶（用於開發和測試HomeKit相關功能）

### 接線流程
1. **ESP32與繼電器模塊連接**：
   - 連接ESP32的一個GPIO腳到繼電器模塊的控制端，以控制門鎖。

2. **連接門鎖和繼電器**：
   - 確保繼電器的輸出端與電子門鎖的控制線相連。

3. **按鈕連接**：
   - 將按鈕的兩端分別連接到ESP32的一個GPIO腳和地線。

### 成果
![IMG_0168](https://hackmd.io/_uploads/BygwcVgryg.png)
![IMG_0169](https://hackmd.io/_uploads/ryzv54xSJx.png)
![3333](https://hackmd.io/_uploads/rJEPqElr1x.jpg)
![image](https://github.com/user-attachments/assets/70b00389-d293-4743-bec1-408fc3717331)




# 參考資料
https://www.studiopieters.nl/homebridge-door-lock/
https://www.studiopieters.nl/esp-homekit-sdk-flash/
https://www.studiopieters.nl/esp8266-homekit-lock/
https://github.com/AchimPieters/Apple-Homebridge-Door-Lock/
https://files.soyal.com.tw/TW/download/protocol/Protocol_881E_725Ev2_82xEv5%204V04.pdf/
https://www.make.com/en

### 採購來源
ICshopping 
飆機器人
米羅科技
新竹 NOVA 勝特力 (百元電子)
### 成果展示(https://www.canva.com/design/DAF3a37FVqM/XxL4vV_lTCStOicCl2zQSw/edit?utm_content=DAF3a37FVqM&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
