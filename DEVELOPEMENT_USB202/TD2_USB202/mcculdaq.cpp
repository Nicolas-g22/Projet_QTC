#include "mcculdaq.h"


MccUldaq::MccUldaq():
    daqDev(nullptr),
    dioDev(nullptr),
    aoDev(nullptr),
    aiDev(nullptr),
    ctrDev(nullptr)
{
    ul::UlDaqDeviceManager::init();
    std::vector<DaqDeviceDescriptor> daqDeviceList = ul::UlDaqDeviceManager::getDaqDeviceInventory(DaqDeviceInterface(ANY_IFC));
    if(daqDeviceList.size()>0)
    {
        descripteur = daqDeviceList.at(0);
        daqDev = &(ul::DaqDevice&) ul::UlDaqDeviceManager::createDaqDevice(daqDeviceList.at(0));
        daqDev->connect();
        InitDio();
        InitAIn();
        InitAOut();
        InitCtr();
    }
}

MccUldaq::~MccUldaq()
{
    if(dioDev)
    {
        DigitalPortType portType = dioDev->getDioInfo().getPortType(0);
        dioDev->dConfigPort(portType,DD_INPUT);
    }

    if(daqDev)
    {
        daqDev->disconnect();
        ul::UlDaqDeviceManager::releaseDaqDevice(*daqDev);
    }
}

UlError MccUldaq::InitDio()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev == nullptr)
            dioDev = daqDev->dioDevice();
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}


UlError MccUldaq::ulDConfigPort(const DigitalDirection _direction, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev)
        {
            dioDev->dConfigPort(_portType,_direction);
            if(_direction == DD_OUTPUT)
                dioDev->dOut(_portType,0);
        }
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDConfigBit(const int _bitNum, const DigitalDirection _direction, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev)
            dioDev->dConfigBit(_portType, _bitNum, _direction);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDioGetInfo(const DioInfoItem _infoItem, const quint8 _index, long &_valeurInfo)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev)
        {
            const ul::UlDioInfo& dioInfo = dioDev->getDioInfo();
            switch(_infoItem)
            {
            case DIO_INFO_NUM_PORTS:
                _valeurInfo = dioInfo.getNumPorts();
                break;
            case DIO_INFO_PORT_TYPE:
                _valeurInfo = dioInfo.getPortType(_index);
                break;
            case DIO_INFO_PORT_IO_TYPE:
                _valeurInfo = dioInfo.getPortIoType(_index);
                break;
            case DIO_INFO_NUM_BITS:
                _valeurInfo = dioInfo.getNumBits(_index);
                break;
            case DIO_INFO_HAS_PACER:
                _valeurInfo = dioInfo.hasPacer(static_cast<DigitalDirection>(_index));
                break;
            case DIO_INFO_SCAN_OPTIONS:
                _valeurInfo = dioInfo.getScanOptions(static_cast<DigitalDirection>(_index));
                break;
            case DIO_INFO_TRIG_TYPES:
                _valeurInfo = dioInfo.getTriggerTypes(static_cast<DigitalDirection>(_index));
                break;
            case DIO_INFO_FIFO_SIZE:
                _valeurInfo = dioInfo.getFifoSize(static_cast<DigitalDirection>(_index));
                break;

            default:
                err = ERR_BAD_INFO_ITEM;
            }
        }
        else
            err = ERR_BAD_DEV_TYPE;
    }
    catch(ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDOut(const quint8 _valeur, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev != nullptr)
            dioDev->dOut(_portType,_valeur);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDIn(quint8 &_valeur, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(dioDev)
            _valeur = dioDev->dIn(_portType);
        else
            err = ERR_BAD_ARG;

    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDBitOut(const int _bitNum, const bool _valeurDuBit, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {

        if(dioDev)
            dioDev->dBitOut(_portType, _bitNum, _valeurDuBit);
        else
            err = ERR_BAD_DEV_TYPE;
    }
    catch(ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDBitIn(const int _bitNum, bool &_valeurDuBit, const DigitalPortType _portType)
{
    UlError err = ERR_NO_ERROR;
    try {

        if(dioDev)
            _valeurDuBit = dioDev->dBitIn(_portType, _bitNum);
        else
            err = ERR_BAD_DEV_TYPE;
    }
    catch(ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulDioGetConfig(quint8 &_valeurConfig)
{
    UlError error = ERR_NO_ERROR;
    try
    {
        if(dioDev)
        {
            ul::UlDioConfig& dioConfig = dioDev->getDioConfig();
            _valeurConfig = static_cast<quint8>(dioConfig.getPortDirectionMask(0));
        }
        else
            error = ERR_BAD_DEV_TYPE;
    }
    catch(ul::UlException& e)
    {
        error = e.getError();
    }
    catch(...)
    {
        error = ERR_UNHANDLED_EXCEPTION;
    }


    return error;
}

UlError MccUldaq::InitAOut()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aoDev == nullptr)
            aoDev = daqDev->aoDevice();
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetNumChanelAOut(int &_numChanel)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            _numChanel = aoDev->getAoInfo().getNumChans();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetResolutionAout(int &_resolution)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            _resolution = aoDev->getAoInfo().getResolution();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulAOut(const int _canal, const double _valeur, const AOutFlag _flags)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aoDev != nullptr)
            aoDev->aOut(_canal,UNI5VOLTS,_flags,_valeur);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::InitAIn()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev == nullptr)
            aiDev = daqDev->aiDevice();
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetNumChanelAIn(int &_numChanel)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            _numChanel = aiDev->getAiInfo().getNumChans();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetResolutionAIn(int &_resolution)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            _resolution = aiDev->getAiInfo().getResolution();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulAIn(const int _canal, double &_valeur, const AInFlag _flags)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            _valeur = aiDev->aIn(_canal,AI_SINGLE_ENDED,BIP10VOLTS,_flags);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulAInScan(const int _lowChan, const int _highChan, const int _samplesPerChan, double *_rate,
                            const ScanOption _options, const AInScanFlag _flags, double data[])
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
            *_rate =aiDev->aInScan(_lowChan,_highChan,AI_SINGLE_ENDED,BIP10VOLTS,_samplesPerChan,*_rate,_options,_flags,data);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulAInScanStop()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
           aiDev->stopBackground();
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulAInScanStatus(ScanStatus &_status, TransferStatus &_transferStatus)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(aiDev != nullptr)
           aiDev->getStatus(&_status,&_transferStatus);
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::InitCtr()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev == nullptr)
            ctrDev = daqDev->ctrDevice();
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetNbCompteur(int &_nbCompteur)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
            _nbCompteur = ctrDev->getCtrInfo().getNumCtrs();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::GetResolutionCtr(int &_resolution)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
            _resolution = ctrDev->getCtrInfo().getResolution();
    }  catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::ulCIn(long &_valeur)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
           {
            _valeur = ctrDev->cIn(0);
        }
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::UlCRead(const CounterRegisterType _registerType, long &_valeur)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
           {
            _valeur = ctrDev->cRead(0,_registerType);
        }
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::UlCLoad(const CounterRegisterType _registerType, const long _valeur)
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
           {
            ctrDev->cLoad(0,_registerType,_valeur);
           }
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}

UlError MccUldaq::UlCClear()
{
    UlError err = ERR_NO_ERROR;
    try {
        if(ctrDev != nullptr)
           {
            ctrDev->cClear(0);
           }
        else
            err = ERR_BAD_DEV_TYPE;
    } catch (ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;
}





UlError MccUldaq::ulFlashLed(const int _flashCount)
{
    UlError err = ERR_NO_ERROR;
    try {
        daqDev->flashLed(_flashCount);
    }
    catch(ul::UlException& e)
    {
        err = e.getError();
    }
    catch(...)
    {
        err = ERR_UNHANDLED_EXCEPTION;
    }
    return err;

}

DaqDeviceDescriptor MccUldaq::getDescripteur() const
{
    return descripteur;
}
