#ifndef PSOD_HW1_GATE_AND_H
#define PSOD_HW1_GATE_AND_H
#include "../basic/Device.h"

/**
 * @class gateAND
 * @brief 代表 AND 邏輯閘的類別，繼承自 Device 基礎類別
 */
class gateAND:public Device{
    public:
        gateAND():Device(){}
        explicit gateAND(Device * d) : Device(d){}
        explicit gateAND(const std::vector<Device *>& _iPins) : Device(_iPins){}
        /**
         * @brief 執行 AND 邏輯運算
         * 只有當所有連線的輸入端 (iPins) 輸出皆為 true 時，此函式才回傳 true
         * @return std::vector<bool> 運算結果（通常為單一元素的向量）
         */
        std::vector<bool> getOutput() override;
};

#endif //PSOD_HW1_GATE_AND_H
