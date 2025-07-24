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

    openknx.func3Button.onShortClick([]()
    {
        openknxSwitchActuatorModule.doSwitchChannel(0, !openknxSwitchActuatorModule.getChannelStatus(0), true);
    });

    openknx.func2Button.onShortClick([]()
    {
        openknxSwitchActuatorModule.doSwitchChannel(1, !openknxSwitchActuatorModule.getChannelStatus(1), true);
    });

    openknx.func1Button.onShortClick([]()
    {
        openknxSwitchActuatorModule.doSwitchChannel(2, !openknxSwitchActuatorModule.getChannelStatus(2), true);
    });
}

void loop()
{
    openknx.loop();
    if(knx.configured())
    {
        openknx.info3Led.setColor(OPENKNX_SERIALLED_COLOR_GREEN);
        openknx.info3Led.on(openknxSwitchActuatorModule.getChannelStatus(0));

        openknx.info2Led.setColor(OPENKNX_SERIALLED_COLOR_GREEN);
        openknx.info2Led.on(openknxSwitchActuatorModule.getChannelStatus(1));

        openknx.info1Led.setColor(OPENKNX_SERIALLED_COLOR_GREEN);
        openknx.info1Led.on(openknxSwitchActuatorModule.getChannelStatus(2));
    }
    else
    {
        openknx.info3Led.setColor(OPENKNX_SERIALLED_COLOR_YELLOW);
        openknx.info3Led.on();

        openknx.info2Led.setColor(OPENKNX_SERIALLED_COLOR_YELLOW);
        openknx.info2Led.on();

        openknx.info1Led.setColor(OPENKNX_SERIALLED_COLOR_YELLOW);
        openknx.info1Led.on();
    }
}