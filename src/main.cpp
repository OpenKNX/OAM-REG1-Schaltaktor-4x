#include "OpenKNX.h"
#include "Logic.h"
#include "FileTransferModule.h"
#include "SwitchActuatorModule.h"


void setup()
{
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);

    openknx.addModule(1, openknxLogic);
    openknx.addModule(2, openknxSwitchActuatorModule);
    openknx.addModule(9, openknxFileTransferModule);
    openknx.setup();
}

void loop()
{
    openknx.loop();
}