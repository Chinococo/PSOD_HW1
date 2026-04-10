#ifndef PSOD_HW1_OUT_PIN_H
#define PSOD_HW1_OUT_PIN_H
#include "Device.h"
/**
 * @class oPin
 * @brief 代表邏輯電路的最終輸出端 (Output Pin)
 * @details 作為電路運算的最終輸出點，負責向前方連接的裝置索取運算結果。
 */
class oPin : public Device {
    /** @brief 儲存輸出訊號來源的裝置指標 */
    std::vector<Device *> output;
public:
    oPin():Device(){};
    explicit oPin(Device *);
    /**
     * @brief 獲取輸出接腳的邏輯準位
     * @details
     * 實作基底類別的純虛擬函數。會呼叫所連接裝置的 getOutput()。
     * @return std::vector<bool> 傳回包含一個布林值的向量（代表 0 或 1）。
     * @throw std::invalid_argument 無法得到output結果時拋出。
     * @override
     */
    std::vector<bool> getOutput() override;
};
#endif
