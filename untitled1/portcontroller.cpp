#include "portcontroller.h"
#include "QSerialPort"
#include "QSerialPortInfo"

PortController::PortController(QObject *parent)
    : QObject{parent}
{
    portIndex = portInfo.availablePorts();
    comCount = portIndex.size();
    QObject::connect(&port, &QSerialPort::readyRead, this, &PortController::handleReadyRead);
    // QSerialPort port;
    // QSerialPortInfo portInfo;
    // int baudRate; //波特率
    // int bitRate;  //数据位
    // int comCount; //可接端口数
    // //  allValues: [freq, bitNum, verify, stopNum, hardwareStream, dtr, rts]
    // //  input, output
    // QString input;
    // QString output;
    // int verify;
    // int stopNum;
    // bool hardwareStream;
    // bool dtr;
    // bool rts;
    // bool open;
}

PortController *PortController::getInstance()
{
    static PortController * obj = new PortController();
    return obj;
}

int PortController::getBaudRate() const
{
    return baudRate;
}

void PortController::setBaudRate(int newBaudRate)
{
    if (baudRate == newBaudRate)
        return;
    baudRate = newBaudRate;
    port.clearError();
    if(port.setBaudRate(newBaudRate) == false){
        setError(port.error());
    }
    emit baudRateChanged();
}

int PortController::getBitRate() const
{
    return bitRate;
}

void PortController::setBitRate(int newBitRate)
{
    if (bitRate == newBitRate)
        return;
    port.clearError();
    bitRate = newBitRate;
    auto setVal = QSerialPort::Data8; //sets the DataBits
    if(newBitRate == 5)
        setVal = QSerialPort::Data5;
    else if(newBitRate == 6)
        setVal = QSerialPort::Data6;
    else if(newBitRate == 7)
        setVal = QSerialPort::Data7;
    if(port.setDataBits(setVal) == false){
        setError(port.error());
    }
    emit bitRateChanged();
}

int PortController::getComCount() const
{
    return comCount;
}

void PortController::setComCount(int newComCount)
{
    if (comCount == newComCount)
        return;
    comCount = newComCount;
    emit comCountChanged();
}

QString PortController::getInput() const
{
    return input;
}

void PortController::setInput(const QString &newInput)
{
    if (input == newInput)
        return;
    input = newInput;
    emit inputChanged();
}

QString PortController::getOutput() const
{
    return output;
}

void PortController::setOutput(const QString &newOutput)
{
    if (output == newOutput)
        return;
    output = newOutput;
    emit outputChanged();
}

int PortController::getVerify() const
{
    return verify;
}

void PortController::setVerify(int newVerify)
{
    if (verify == newVerify)
        return;
    port.clearError();
    verify = newVerify;
    auto setPa = QSerialPort::NoParity; //sets Parity
    if(verify == 1)
        setPa = QSerialPort::EvenParity;
    else if(verify == 2)
        setPa = QSerialPort::MarkParity;
    else if(verify == 3)
        setPa = QSerialPort::OddParity;
    if(port.setParity(setPa) == false){
        setError(port.error());
    }
    emit verifyChanged();
}

int PortController::getStopNum() const
{
    return stopNum;
}

void PortController::setStopNum(int newStopNum)
{
    if (stopNum == newStopNum)
        return;
    port.clearError();
    stopNum = newStopNum;
    auto setStop = QSerialPort::OneStop;
    if(stopNum == 1.5)
        setStop = QSerialPort::OneAndHalfStop;
    else if(stopNum == 2)
        setStop = QSerialPort::TwoStop;
    if(port.setStopBits(setStop) == false){
        setError(port.error());
    }
    emit stopNumChanged();
}

bool PortController::getHardwareStream() const
{
    return hardwareStream;
}

void PortController::setHardwareStream(bool newHardwareStream)
{
    if (hardwareStream == newHardwareStream)
        return;
    port.clearError();
    hardwareStream = newHardwareStream;
    if(hardwareStream == false){   //sets the hardware stream
        port.setFlowControl(QSerialPort::NoFlowControl);
    } else {
        port.setFlowControl(QSerialPort::HardwareControl);
    }
    if(port.error() != 0){
        setError(port.error());
    }
    emit hardwareStreamChanged();
}

bool PortController::getDtr() const
{
    return dtr;
}

void PortController::setDtr(bool newDtr)
{
    if (dtr == newDtr)
        return;
    dtr = newDtr;
    if(open == true && port.setDataTerminalReady(dtr) == false){
        port.clearError();
        setError(port.error());
    }
    emit dtrChanged();
}

bool PortController::getRts() const
{
    return rts;
}

void PortController::setRts(bool newRts)
{
    if (rts == newRts)
        return;
    rts = newRts;
    port.clearError();
    if(open == true && port.setRequestToSend(rts) == false){
        setError(port.error());
    }
    emit rtsChanged();
}

bool PortController::getOpen() const
{
    return open;
}

void PortController::setOpen(bool newOpen)
{
    if (open == newOpen)
        return;
    open = newOpen;
    if (open)
        openPort();
    else
        closePort();
    printAllVars();
    emit openChanged();
}


QStringList PortController::getAllPorts()
{
    refreshPorts();
    QStringList *ans = new QStringList();
    const auto serialPortInfos = portInfo.availablePorts();
    for(const QSerialPortInfo &portInfo : serialPortInfos){
        ans->append(portInfo.portName());
        ans->append(portInfo.description());
    }
    return *ans;
}

void PortController::openPort()
{
    port.clearError();
    port.setPort(portIndex[index]);
    if(port.open(QIODeviceBase::ReadWrite) == false){
        setError(port.error());
        qDebug() << port.open(QIODeviceBase::ReadWrite) << " why";
        qDebug() << "error detected";
        emit portSwitchError();
        return;
    } else {
        qDebug() << "port actually opened";
    }
    updatePort();
    port.clearError();
}

void PortController::updatePort() //later on would return all the logic back to its owners
{
    port.setBaudRate(baudRate); //setting baudRate
    auto setVal = QSerialPort::Data8; //sets the DataBits
    if(bitRate == 5)
        setVal = QSerialPort::Data5;
    else if(bitRate == 6)
        setVal = QSerialPort::Data6;
    else if(bitRate == 7)
        setVal = QSerialPort::Data7;
    port.setDataBits(setVal);
    auto setPa = QSerialPort::NoParity; //sets Parity
    if(verify == 1)
        setPa = QSerialPort::EvenParity;
    else if(verify == 2)
        setPa = QSerialPort::MarkParity;
    else if(verify == 3)
        setPa = QSerialPort::OddParity;
    port.setParity(setPa);
    auto setStop = QSerialPort::OneStop; //sets the stopBits
    if(stopNum == 1.5)
        setStop = QSerialPort::OneAndHalfStop;
    else if(stopNum == 2)
        setStop = QSerialPort::TwoStop;
    port.setStopBits(setStop);
    if(hardwareStream == false){   //sets the hardware stream
        port.setFlowControl(QSerialPort::NoFlowControl);
    } else {
        port.setFlowControl(QSerialPort::HardwareControl);
    }
    if(open == true){
        port.setRequestToSend(rts);
        port.setDataTerminalReady(dtr);
    }
    if(port.error() != 0){
        this->setError(port.error());
    }
    port.clearError();
}

void PortController::refreshPorts()
{
    const auto newInfo = portInfo.availablePorts();
    if(newInfo.length() != portIndex.length()){
        portIndex = newInfo;
        setComCount(portIndex.count());
        return;
    }
    for(int i = 0; i<newInfo.length(); i++){
        if(i < portIndex.length()){
            if(portIndex[i].serialNumber().compare(newInfo[i].serialNumber())){
                portIndex = newInfo;
                return;
            }
        }
    }

    return;
}


void PortController::closePort()
{
    port.setPort(portIndex[index]);
    port.close();
    port.clearError();
}

QString PortController::read()
{
    return port.readAll();
}

void PortController::write(QString input)
{
    port.write(input.toUtf8());
}

QList<bool> PortController::updatePinOut()
{
    QList<bool> *ans = new QList<bool>();
    const auto pinout = port.pinoutSignals();
    ans->append(pinout & QSerialPort::RingIndicatorSignal);
    ans->append(pinout & QSerialPort::DataSetReadySignal);
    ans->append(pinout & QSerialPort::ClearToSendSignal);
    return *ans;
}

int PortController::getError() const
{
    return error;
}

void PortController::setError(int newError)
{
    if (error == newError)
        return;
    error = newError;
    emit errorChanged();
}

int PortController::getIndex() const
{
    return index;
}

void PortController::setIndex(int newIndex) //must warn if the port is already in use, and must execute switch
{
    if (index == newIndex)
        return;
    index = newIndex;
    if(index >= 0 && index < portIndex.size()){
        port.setPort(portIndex[index]);
        if(open == true){
            openPort();
        }
    }
    emit indexChanged();
}

void PortController::handleReadyRead()
{
    emit readSig(port.readAll());
}





void PortController::printAllVars()
{
    qDebug() << "Baud Rate: " << baudRate << "\nBitRate: " << bitRate;
}



