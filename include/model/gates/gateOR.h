#ifndef PSOD_HW1_GATE_OR_H
#define PSOD_HW1_GATE_OR_H
#include "../basic/Device.h"

/**
 * @class gateOR
 * @brief 代表 OR 邏輯閘的類別，繼承自 Device 基底類別
 */
class gateOR :public Device{
public:
    gateOR():Device(){}
    explicit gateOR(Device * d) : Device(d){}

    /**
     * @brief 使用一組輸入引腳初始化 OR 閘
     * @param _iPins 包含多個輸入來源的向量
     */
    explicit gateOR(const std::vector<Device *>& _iPins) : Device(_iPins){}

    /**
     * @brief 實作 OR 邏輯運算
     * 覆寫基底類別的虛擬函式，計算所有輸入端進行 OR 運算後的結果
     * @return std::vector<bool> 運算後的輸出數值集合
     */
    std::vector<bool> getOutput() override;
};

#endif //PSOD_HW1_GATE_OR_H
