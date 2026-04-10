#ifndef PSOD_HW1_IN_PIN_H
#define PSOD_HW1_IN_PIN_H
#include "Device.h"
/**
 * @class iPin
 * @brief 代表電路的輸入引腳 (Input Pin)，作為訊號輸入的起點
 */
class iPin : public Device {
    /** 儲存此輸入引腳目前的邏輯狀態 (0 或 1) */
    std::vector<bool> output;
public:
    iPin():Device(){};
    /**
     * @brief 具備初始值的建構子
     * @param _input 初始的邏輯狀態（true/false）
     * 使用 explicit 避免將 bool 隱式轉換為 iPin 物件
     */
    explicit iPin(bool _input);
    /**
     * @brief 獲取輸入引腳的當前狀態
     * @return std::vector<bool> 包含引腳狀態的輸出
     */
    std::vector<bool> getOutput() override;
};


#endif
