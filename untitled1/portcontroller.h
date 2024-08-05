#ifndef PORTCONTROLLER_H
#define PORTCONTROLLER_H

#include <QObject>
#include <QTQml>
#include <QSerialPort>
#include <QSerialPortInfo>
class PortController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit PortController(QObject *parent = nullptr);
    static PortController *getInstance();

    int getBaudRate() const;
    void setBaudRate(int newBaudRate);

    int getBitRate() const;
    void setBitRate(int newBitRate);

    int getComCount() const;
    void setComCount(int newComCount);
    QString getInput() const;
    void setInput(const QString &newInput);

    QString getOutput() const;
    void setOutput(const QString &newOutput);

    int getVerify() const;
    void setVerify(int newVerify);

    int getStopNum() const;
    void setStopNum(int newStopNum);

    bool getHardwareStream() const;
    void setHardwareStream(bool newHardwareStream);

    bool getDtr() const;
    void setDtr(bool newDtr);

    bool getRts() const;
    void setRts(bool newRts);

    bool getOpen() const;
    void setOpen(bool newOpen);

    Q_INVOKABLE QStringList getAllPorts();

    Q_INVOKABLE void openPort();
    Q_INVOKABLE void closePort();
    Q_INVOKABLE QString read();
    Q_INVOKABLE void write(QString input);
    Q_INVOKABLE QList<bool> updatePinOut();
    void updatePort();
    void refreshPorts();

    int getError() const;
    void setError(int newError);

    int getIndex() const;
    void setIndex(int newIndex);
private slots:
    void handleReadyRead();
private:
    QSerialPort port;
    QSerialPortInfo portInfo;
    QList<QSerialPortInfo> portIndex;
    int index; //the portIndex
    int baudRate; //波特率
    int bitRate;  //数据位
    int comCount; //可接端口数
//  allValues: [freq, bitNum, verify, stopNum, hardwareStream, dtr, rts]
//  input, output
    QString input;
    QString output;
    int verify;
    int stopNum;
    bool hardwareStream;
    bool dtr;
    bool rts;
    bool open;
    int error;

    //baudRate, bitRate, comCount, input, output, verify, stopNum, hardwareStream, dtr, rts
    Q_PROPERTY(int baudRate READ getBaudRate WRITE setBaudRate NOTIFY baudRateChanged FINAL)

    Q_PROPERTY(int bitRate READ getBitRate WRITE setBitRate NOTIFY bitRateChanged FINAL)

    Q_PROPERTY(int comCount READ getComCount WRITE setComCount NOTIFY comCountChanged FINAL)

    Q_PROPERTY(QString input READ getInput WRITE setInput NOTIFY inputChanged FINAL)

    Q_PROPERTY(QString output READ getOutput WRITE setOutput NOTIFY outputChanged FINAL)

    Q_PROPERTY(int verify READ getVerify WRITE setVerify NOTIFY verifyChanged FINAL)

    Q_PROPERTY(int stopNum READ getStopNum WRITE setStopNum NOTIFY stopNumChanged FINAL)

    Q_PROPERTY(bool hardwareStream READ getHardwareStream WRITE setHardwareStream NOTIFY hardwareStreamChanged FINAL)

    Q_PROPERTY(bool dtr READ getDtr WRITE setDtr NOTIFY dtrChanged FINAL)

    Q_PROPERTY(bool rts READ getRts WRITE setRts NOTIFY rtsChanged FINAL)

    Q_PROPERTY(bool open READ getOpen WRITE setOpen NOTIFY openChanged FINAL)

    Q_PROPERTY(int error READ getError WRITE setError NOTIFY errorChanged FINAL)

    Q_PROPERTY(int index READ getIndex WRITE setIndex NOTIFY indexChanged FINAL)

    void printAllVars();

signals:
    void portSwitchError();
    void readSig(QByteArray data);
    void baudRateChanged();
    void bitRateChanged();
    void comCountChanged();
    void inputChanged();
    void outputChanged();
    void verifyChanged();
    void stopNumChanged();
    void hardwareStreamChanged();
    void dtrChanged();
    void rtsChanged();
    void openChanged();
    void errorChanged();
    void indexChanged();
};

#endif // PORTCONTROLLER_H
