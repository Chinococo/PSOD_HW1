#ifndef PSOD_HW1_GATE_NOT_H
#define PSOD_HW1_GATE_NOT_H
#include "../basic/Device.h"
/**
 * @class gateNot
 * @brief 代表 NOT 邏輯閘（反向器）的類別，繼承自 Device
 */
class gateNot :public Device{
public:
    gateNot():Device(){}
    explicit gateNot(Device * d) : Device(d){}
    /**
     * @brief 實作 NOT 邏輯運算
     * 將輸入端的第一個訊號進行反向處裡 (0 變 1, 1 變 0)
     * @return std::vector<bool> 包含反向結果的向量
     */
    std::vector<bool> getOutput() override;
};

#endif //PSOD_HW1_GATE_NOT_H
