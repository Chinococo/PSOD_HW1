#ifndef PSOD_HW1_LOGIC_SIMULATOR_H
#define PSOD_HW1_LOGIC_SIMULATOR_H
#include "model/basic/Device.h"
#include <string>
#include <ostream>
/**
 * @class LogicSimulator
 * @brief 核心邏輯模擬類別，負責讀取電路檔、儲存元件結構並進行模擬運算
 */
class LogicSimulator {
    /** 儲存電路中所有的元件（包含邏輯閘、輸入與輸出引腳） */
    std::vector<Device *> circuit;
    /** 專門存放輸入引腳 (Input Pins) 的指標，方便快速設定模擬數值 */
    std::vector<Device *> iPins;
    /** 專門存放輸出引腳 (Output Pins) 的指標，用於獲取最終模擬結果 */
    std::vector<Device *> oPins;

public:
    ~LogicSimulator();
    /**
     * @brief 執行電路模擬並獲取結果
     * @param _inputs 指定要觀察的輸出引腳集合
     * @return std::string 回傳模擬後的電路狀態字串（例如 "0101"）
     */
    [[nodiscard]] std::string getSimulationResult(const std::vector<Device*> &_inputs) const;

    /**
     * @brief 產生該電路的真值表 (Truth Table)
     * @return std::string 包含所有輸入組合與對應輸出結果的完整表格字串
     */
    [[nodiscard]] std::string getTruthTable() const;;

    /**
     * @brief 從指定路徑載入電路定義檔 (.lcf)
     * @param path 檔案路徑字串
     * @return true 讀取並解析成功, false 檔案不存在或格式錯誤
     */
    bool load(const std::string& path);
    /**
     * @brief 自定義電路資訊的輸出格式
     * 讓你可以直接用 std::cout << simulator 來印出電路摘要（如引腳與邏輯閘數量）。
     * * @param os 輸出目標（如螢幕）
     * @param ls 要印出的模擬器物件
     * @return 支援連續輸出（例如：cout << ls << " Done";）
     */
    friend std::ostream& operator<<(std::ostream& os, const LogicSimulator& ls);
    [[nodiscard]] size_t getCircuitSize() const { return circuit.size(); }
    [[nodiscard]] size_t getIPinSize() const { return iPins.size(); }
    [[nodiscard]] size_t getOPinSize() const { return oPins.size(); }
};


#endif //PSOD_HW1_LOGIC_SIMULATOR_H
