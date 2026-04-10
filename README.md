# Pattern-Oriented Software Design Hw1
## File Architecture
```
├─include               
│  ├─model              
│  │  ├─basic            (iPin/oPin 宣告)
│  │  ├─control          (controller宣告)
│  │  └─gates            (gateNot/gateAND/gateOR宣告)
│  ├─utils               
│  └─view                (顯示介面/UI 邏輯)
├─src                    
│  ├─control             
│  ├─model               
│  │  ├─basic            (iPin/oPin實作)
│  │  └─gates            (gateNot/gateAND/gateOR)
│  ├─utils
│  └─view

├─test                   (單元測試)
│  └─static              (測試用的靜態資料)
└─README.md              (此說明文檔)
└─CMakeLists.txt         (專案設定檔)
└─main.cpp               (手動程式進入點)
└─test.cpp               (GTest程式進入點)
```
## UML
```mermaid
classDiagram
    class Device {
        <<abstract>>
        # iPins: vector~Device*~
        # output: vector~bool~
        + addInputPin(Device* iPin) void
        + getOutput()* vector~bool~
    }

    class iPin {
        +iPin(bool _input)
        +getOutput() vector~bool~
    }

    class oPin {
        +oPin(Device* _input)
        +getOutput() vector~bool~
    }

    class gateAND {
        +getOutput() vector~bool~
    }

    class gateOR {
        +getOutput() vector~bool~
    }

    class gateNot {
        +getOutput() vector~bool~
    }

    class LogicSimulator {
        - circuit: vector~Device*~
        - iPins: vector~Device*~
        - oPins: vector~Device*~
        +load(string path) bool
        +getSimulationResult(vector~Device*~ inputs) string
        +getTruthTable() string
    }

    class TextUI {
        - logic_simulator: LogicSimulator
        - isLoad: bool
        - isFinished: bool
        +displayMenu()$ void
        +processCommand() void
        +isFinish() bool
    }

    class controller {
        -text_ui: TextUI
        +process() void
    }
    class Main{

    }

    %% 繼承關係
    Device <|-- iPin
    Device <|-- oPin
    Device <|-- gateAND
    Device <|-- gateOR
    Device <|-- gateNot

    %% 組合與關聯關係
    Main --> controller
    Device -->  Device 
    LogicSimulator "1" -->  "many" Device
    TextUI  -->  LogicSimulator
    controller -->  TextUI
```
