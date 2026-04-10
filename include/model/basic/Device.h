#ifndef PSOD_HW1_DEVICE_H
#define PSOD_HW1_DEVICE_H
#include <vector>

/**
 * @class Device
 * @brief 所有邏輯元件（邏輯閘、引腳）的抽象基底類別
 */
class Device {
protected:
    /** * @brief 儲存此元件的所有輸入來源
     * 使用 protected 讓子類別（如 gateAND）能存取輸入端進行運算
     */
    std::vector<Device *> iPins;
public:
    virtual ~Device() = default;

    Device()= default;

    explicit Device(Device *_iPin) {
        Device::addInputPin(_iPin);
    }
    explicit Device(const std::vector<Device *>& _iPins) {
        for (Device * _iPin : _iPins)
            Device::addInputPin(_iPin);
    }
    /** * @brief 增加一個輸入來源
     * @param iPin 指向欲連結之輸入元件的指標
     */
    void addInputPin(Device *iPin);
    /** * @brief 純虛擬函式：獲取元件輸出
     * 要求所有繼承 Device 的子類別必須實作自己的邏輯運算方式
     * @return std::vector<bool> 運算後的輸出結果
     */
    virtual std::vector<bool> getOutput() = 0;
};

#endif //PSOD_HW1_DEVICE_H
