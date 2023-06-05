/*************************************************************************************************************************************
 **                  maxon motor ag, CH-6072 Sachseln
 **************************************************************************************************************************************
 **
 ** FILE:            Definitions.h
 **
 ** Summary:         Functions for Linux shared library
 **
 ** Date:            11.2018
 ** Target:          x86, x86_64, arm (sf,hf,aarch64)
 ** Devices:         EPOS, EPOS2, EPOS4
 ** Written by:      maxon motor ag, CH-6072 Sachseln
 **
 *************************************************************************************************************************************/

#include <stdint.h>

#ifndef _H_LINUX_EPOSCMD_
#define _H_LINUX_EPOSCMD_

//Communication
int32_t CreateCommunication();
int32_t DeleteCommunication();

// Data Recorder
int32_t CreateDataRecorderCmdManager(void* KeyHandle);
int32_t DeleteDataRecorderCmdManager();

/*************************************************************************************************************************************
 * INITIALISATION FUNCTIONS
 *************************************************************************************************************************************/

//Communication
void*  VCS_OpenDevice(char* DeviceName, char* ProtocolStackName, char* InterfaceName, char* PortName, uint32_t* pErrorCode);
int32_t  VCS_SetProtocolStackSettings(void* KeyHandle, uint32_t Baudrate, uint32_t Timeout, uint32_t* pErrorCode);
int32_t  VCS_GetProtocolStackSettings(void* KeyHandle, uint32_t* pBaudrate, uint32_t* pTimeout, uint32_t* pErrorCode);
int32_t  VCS_CloseDevice(void* KeyHandle, uint32_t* pErrorCode);
int32_t  VCS_CloseAllDevices(uint32_t* pErrorCode);

//Gateway
int32_t VCS_SetGatewaySettings(void* KeyHandle, uint32_t Baudrate, uint32_t* pErrorCode);
int32_t VCS_GetGatewaySettings(void* KeyHandle, uint32_t* pBaudrate, uint32_t* pErrorCode);

//Sub device
void* VCS_OpenSubDevice(void* DeviceHandle, char* DeviceName, char* ProtocolStackName, uint32_t* pErrorCode);
int32_t VCS_CloseSubDevice(void* KeyHandle, uint32_t* pErrorCode);
int32_t VCS_CloseAllSubDevices(void* DeviceHandle, uint32_t* pErrorCode);

//Info
int32_t  VCS_GetDriverInfo(char* p_pszLibraryName, uint16_t p_usMaxLibraryNameStrSize,char* p_pszLibraryVersion, uint16_t p_usMaxLibraryVersionStrSize, uint32_t* p_pErrorCode);
int32_t  VCS_GetVersion(void* KeyHandle, uint16_t NodeId, uint16_t* pHardwareVersion, uint16_t* pSoftwareVersion, uint16_t* pApplicationNumber, uint16_t* pApplicationVersion, uint32_t* pErrorCode);
int32_t  VCS_GetErrorInfo(uint32_t ErrorCodeValue, char* pErrorInfo, uint16_t MaxStrSize);

//Advanced Functions
int32_t  VCS_GetDeviceNameSelection(int32_t StartOfSelection, char* pDeviceNameSel, uint16_t MaxStrSize, int* pEndOfSelection, uint32_t* pErrorCode);
int32_t  VCS_GetProtocolStackNameSelection(char* DeviceName, int32_t StartOfSelection, char* pProtocolStackNameSel, uint16_t MaxStrSize, int* pEndOfSelection, uint32_t* pErrorCode);
int32_t  VCS_GetInterfaceNameSelection(char* DeviceName, char* ProtocolStackName, int32_t StartOfSelection, char* pInterfaceNameSel, uint16_t MaxStrSize, int* pEndOfSelection, uint32_t* pErrorCode);
int32_t  VCS_GetPortNameSelection(char* DeviceName, char* ProtocolStackName, char* InterfaceName, int32_t StartOfSelection, char* pPortSel, uint16_t MaxStrSize, int* pEndOfSelection, uint32_t* pErrorCode);
int32_t  VCS_ResetPortNameSelection(char* DeviceName, char* ProtocolStackName, char* InterfaceName, uint32_t* pErrorCode);
int32_t  VCS_GetBaudrateSelection(char* DeviceName, char* ProtocolStackName, char* InterfaceName, char* PortName, int32_t StartOfSelection, uint32_t* pBaudrateSel, int* pEndOfSelection, uint32_t* pErrorCode);
int32_t  VCS_GetKeyHandle(char* DeviceName, char* ProtocolStackName, char* InterfaceName, char* PortName, void** pKeyHandle, uint32_t* pErrorCode);
int32_t  VCS_GetDeviceName(void* KeyHandle, char* pDeviceName, uint16_t MaxStrSize, uint32_t* pErrorCode);
int32_t  VCS_GetProtocolStackName(void* KeyHandle, char* pProtocolStackName, uint16_t MaxStrSize, uint32_t* pErrorCode);
int32_t  VCS_GetInterfaceName(void* KeyHandle, char* pInterfaceName, uint16_t MaxStrSize, uint32_t* pErrorCode);
int32_t  VCS_GetPortName(void* KeyHandle, char* pPortName, uint16_t MaxStrSize, uint32_t* pErrorCode);

/*************************************************************************************************************************************
 * CONFIGURATION FUNCTIONS
 *************************************************************************************************************************************/

//General
int32_t  VCS_SetObject(void* KeyHandle, uint16_t NodeId, uint16_t ObjectIndex, uint8_t ObjectSubIndex, void* pData, uint32_t NbOfBytesToWrite, uint32_t* pNbOfBytesWritten, uint32_t* pErrorCode);
int32_t  VCS_GetObject(void* KeyHandle, uint16_t NodeId, uint16_t ObjectIndex, uint8_t ObjectSubIndex, void* pData, uint32_t NbOfBytesToRead, uint32_t* pNbOfBytesRead, uint32_t* pErrorCode);
int32_t  VCS_Restore(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_Store(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Advanced Functions
//Motor
int32_t  VCS_SetMotorType(void* KeyHandle, uint16_t NodeId, uint16_t MotorType, uint32_t* pErrorCode);
int32_t  VCS_SetDcMotorParameter(void* KeyHandle, uint16_t NodeId, uint16_t NominalCurrent, uint16_t MaxOutputCurrent, uint16_t ThermalTimeConstant, uint32_t* pErrorCode);
int32_t  VCS_SetDcMotorParameterEx(void* KeyHandle, uint16_t NodeId, uint32_t NominalCurrent, uint32_t MaxOutputCurrent, uint16_t ThermalTimeConstant, uint32_t* pErrorCode);
int32_t  VCS_SetEcMotorParameter(void* KeyHandle, uint16_t NodeId, uint16_t NominalCurrent, uint16_t MaxOutputCurrent, uint16_t ThermalTimeConstant, uint8_t NbOfPolePairs, uint32_t* pErrorCode);
int32_t  VCS_SetEcMotorParameterEx(void* KeyHandle, uint16_t NodeId, uint32_t NominalCurrent, uint32_t MaxOutputCurrent, uint16_t ThermalTimeConstant, uint8_t NbOfPolePairs, uint32_t* pErrorCode);
int32_t  VCS_GetMotorType(void* KeyHandle, uint16_t NodeId, uint16_t* pMotorType, uint32_t* pErrorCode);
int32_t  VCS_GetDcMotorParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pNominalCurrent, uint16_t* pMaxOutputCurrent, uint16_t* pThermalTimeConstant, uint32_t* pErrorCode);
int32_t  VCS_GetDcMotorParameterEx(void* KeyHandle, uint16_t NodeId, uint32_t* pNominalCurrent, uint32_t* pMaxOutputCurrent, uint16_t* pThermalTimeConstant, uint32_t* pErrorCode);
int32_t  VCS_GetEcMotorParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pNominalCurrent, uint16_t* pMaxOutputCurrent, uint16_t* pThermalTimeConstant, unsigned char* pNbOfPolePairs, uint32_t* pErrorCode);
int32_t  VCS_GetEcMotorParameterEx(void* KeyHandle, uint16_t NodeId, uint32_t* pNominalCurrent, uint32_t* pMaxOutputCurrent, uint16_t* pThermalTimeConstant, unsigned char* pNbOfPolePairs, uint32_t* pErrorCode);

//Sensor
int32_t  VCS_SetSensorType(void* KeyHandle, uint16_t NodeId, uint16_t SensorType, uint32_t* pErrorCode);
int32_t  VCS_SetIncEncoderParameter(void* KeyHandle, uint16_t NodeId, uint32_t EncoderResolution, int32_t InvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_SetHallSensorParameter(void* KeyHandle, uint16_t NodeId, int32_t InvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_SetSsiAbsEncoderParameter(void* KeyHandle, uint16_t NodeId, uint16_t DataRate, uint16_t NbOfMultiTurnDataBits, uint16_t NbOfSingleTurnDataBits, int32_t InvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_SetSsiAbsEncoderParameterEx(void* KeyHandle, uint16_t NodeId, uint16_t DataRate, uint16_t NbOfMultiTurnDataBits, uint16_t NbOfSingleTurnDataBits, uint16_t NbOfSpecialDataBits, int32_t InvertedPolarity, uint16_t Timeout, uint16_t PowerupTime, uint32_t* pErrorCode);
int32_t  VCS_SetSsiAbsEncoderParameterEx2(void* KeyHandle, uint16_t NodeId, uint16_t DataRate, uint16_t NbOfSpecialDataBitsLeading, uint16_t NbOfMultiTurnDataBits, uint16_t NbOfMultiTurnPositionBits, uint16_t NbOfSingleTurnDataBits, uint16_t NbOfSingleTurnPositionBits, uint16_t NbOfSpecialDataBitsTrailing, int32_t InvertedPolarity, uint16_t Timeout, uint16_t PowerupTime, int32_t CheckFrame, int32_t ReferenceReset, uint32_t* pErrorCode);
int32_t  VCS_GetSensorType(void* KeyHandle, uint16_t NodeId, uint16_t* pSensorType, uint32_t* pErrorCode);
int32_t  VCS_GetIncEncoderParameter(void* KeyHandle, uint16_t NodeId, uint32_t* pEncoderResolution, int* pInvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_GetHallSensorParameter(void* KeyHandle, uint16_t NodeId, int* pInvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_GetSsiAbsEncoderParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pDataRate, uint16_t* pNbOfMultiTurnDataBits, uint16_t* pNbOfSingleTurnDataBits, int* pInvertedPolarity, uint32_t* pErrorCode);
int32_t  VCS_GetSsiAbsEncoderParameterEx(void* KeyHandle, uint16_t NodeId, uint16_t* pDataRate, uint16_t* pNbOfMultiTurnDataBits, uint16_t* pNbOfSingleTurnDataBits, uint16_t* pNbOfSpecialDataBits, int* pInvertedPolarity, uint16_t* pTimeout, uint16_t* pPowerupTime, uint32_t* pErrorCode);
int32_t  VCS_GetSsiAbsEncoderParameterEx2(void* KeyHandle, uint16_t NodeId, uint16_t* pDataRate, uint16_t* pNbOfSpecialDataBitsLeading, uint16_t* pNbOfMultiTurnDataBits, uint16_t* pNbOfMultiTurnPositionBits, uint16_t* pNbOfSingleTurnDataBits, uint16_t* pNbOfSingleTurnPositionBits, uint16_t* pNbOfSpecialDataBitsTrailing, int* pInvertedPolarity, uint16_t* pTimeout, uint16_t* pPowerupTime, int* pCheckFrame, int* pReferenceReset, uint32_t* pErrorCode);

//Safety
int32_t  VCS_SetMaxFollowingError(void* KeyHandle, uint16_t NodeId, uint32_t MaxFollowingError, uint32_t* pErrorCode);
int32_t  VCS_GetMaxFollowingError(void* KeyHandle, uint16_t NodeId, uint32_t* pMaxFollowingError, uint32_t* pErrorCode);
int32_t  VCS_SetMaxProfileVelocity(void* KeyHandle, uint16_t NodeId, uint32_t MaxProfileVelocity, uint32_t* pErrorCode);
int32_t  VCS_GetMaxProfileVelocity(void* KeyHandle, uint16_t NodeId, uint32_t* pMaxProfileVelocity, uint32_t* pErrorCode);
int32_t  VCS_SetMaxAcceleration(void* KeyHandle, uint16_t NodeId, uint32_t MaxAcceleration, uint32_t* pErrorCode);
int32_t  VCS_GetMaxAcceleration(void* KeyHandle, uint16_t NodeId, uint32_t* pMaxAcceleration, uint32_t* pErrorCode);

//Controller Gains
int32_t VCS_SetControllerGain(void* KeyHandle, uint16_t NodeId, uint16_t EController, uint16_t EGain, unsigned long long Value, uint32_t* pErrorCode);
int32_t VCS_GetControllerGain(void* KeyHandle, uint16_t NodeId, uint16_t EController, uint16_t EGain, unsigned long long* pValue, uint32_t* pErrorCode);

//Inputs/Outputs
int32_t  VCS_DigitalInputConfiguration(void* KeyHandle, uint16_t NodeId, uint16_t DigitalInputNb, uint16_t Configuration, int32_t Mask, int32_t Polarity, int32_t ExecutionMask, uint32_t* pErrorCode);
int32_t  VCS_DigitalOutputConfiguration(void* KeyHandle, uint16_t NodeId, uint16_t DigitalOutputNb, uint16_t Configuration, int32_t State, int32_t Mask, int32_t Polarity, uint32_t* pErrorCode);
int32_t  VCS_AnalogInputConfiguration(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNb, uint16_t Configuration, int32_t ExecutionMask, uint32_t* pErrorCode);
int32_t  VCS_AnalogOutputConfiguration(void* KeyHandle, uint16_t NodeId, uint16_t AnalogOutputNb, uint16_t Configuration, uint32_t* pErrorCode);

//Units
int32_t  VCS_SetVelocityUnits(void* KeyHandle, uint16_t NodeId, uint8_t VelDimension, int8_t VelNotation, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityUnits(void* KeyHandle, uint16_t NodeId, unsigned char* pVelDimension, char* pVelNotation, uint32_t* pErrorCode);

//Compatibility Functions (do not use)
int32_t  VCS_SetPositionRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t P, uint16_t I, uint16_t D, uint32_t* pErrorCode);
int32_t  VCS_SetPositionRegulatorFeedForward(void* KeyHandle, uint16_t NodeId, uint16_t VelocityFeedForward, uint16_t AccelerationFeedForward, uint32_t* pErrorCode);
int32_t  VCS_GetPositionRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t* pP, uint16_t* pI, uint16_t* pD, uint32_t* pErrorCode);
int32_t  VCS_GetPositionRegulatorFeedForward(void* KeyHandle, uint16_t NodeId, uint16_t* pVelocityFeedForward, uint16_t* pAccelerationFeedForward, uint32_t* pErrorCode);

int32_t  VCS_SetVelocityRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t P, uint16_t I, uint32_t* pErrorCode);
int32_t  VCS_SetVelocityRegulatorFeedForward(void* KeyHandle, uint16_t NodeId, uint16_t VelocityFeedForward, uint16_t AccelerationFeedForward, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t* pP, uint16_t* pI, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityRegulatorFeedForward(void* KeyHandle, uint16_t NodeId, uint16_t* pVelocityFeedForward, uint16_t* pAccelerationFeedForward, uint32_t* pErrorCode);

int32_t  VCS_SetCurrentRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t P, uint16_t I, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentRegulatorGain(void* KeyHandle, uint16_t NodeId, uint16_t* pP, uint16_t* pI, uint32_t* pErrorCode);

/*************************************************************************************************************************************
 * OPERATION FUNCTIONS
 *************************************************************************************************************************************/

//OperationMode
int32_t  VCS_SetOperationMode(void* KeyHandle, uint16_t NodeId, char OperationMode, uint32_t* pErrorCode);
int32_t  VCS_GetOperationMode(void* KeyHandle, uint16_t NodeId, char* pOperationMode, uint32_t* pErrorCode);

//StateMachine
int32_t  VCS_ResetDevice(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetState(void* KeyHandle, uint16_t NodeId, uint16_t State, uint32_t* pErrorCode);
int32_t  VCS_SetEnableState(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetDisableState(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetQuickStopState(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_ClearFault(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_GetState(void* KeyHandle, uint16_t NodeId, uint16_t* pState, uint32_t* pErrorCode);
int32_t  VCS_GetEnableState(void* KeyHandle, uint16_t NodeId, int* pIsEnabled, uint32_t* pErrorCode);
int32_t  VCS_GetDisableState(void* KeyHandle, uint16_t NodeId, int* pIsDisabled, uint32_t* pErrorCode);
int32_t  VCS_GetQuickStopState(void* KeyHandle, uint16_t NodeId, int* pIsQuickStopped, uint32_t* pErrorCode);
int32_t  VCS_GetFaultState(void* KeyHandle, uint16_t NodeId, int* pIsInFault, uint32_t* pErrorCode);

//ErrorHandling
int32_t  VCS_GetNbOfDeviceError(void* KeyHandle, uint16_t NodeId, uint8_t *pNbDeviceError, uint32_t *pErrorCode);
int32_t  VCS_GetDeviceErrorCode(void* KeyHandle, uint16_t NodeId, uint8_t DeviceErrorNumber, uint32_t *pDeviceErrorCode, uint32_t *pErrorCode);

//Motion Info
int32_t  VCS_GetMovementState(void* KeyHandle, uint16_t NodeId, int* pTargetReached, uint32_t* pErrorCode);
int32_t  VCS_GetPositionIs(void* KeyHandle, uint16_t NodeId, int* pPositionIs, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityIs(void* KeyHandle, uint16_t NodeId, int* pVelocityIs, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityIsAveraged(void* KeyHandle, uint16_t NodeId, int* pVelocityIsAveraged, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentIs(void* KeyHandle, uint16_t NodeId, short* pCurrentIs, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentIsEx(void* KeyHandle, uint16_t NodeId, int* pCurrentIs, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentIsAveraged(void* KeyHandle, uint16_t NodeId, short* pCurrentIsAveraged, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentIsAveragedEx(void* KeyHandle, uint16_t NodeId, int* pCurrentIsAveraged, uint32_t* pErrorCode);
int32_t  VCS_WaitForTargetReached(void* KeyHandle, uint16_t NodeId, uint32_t Timeout, uint32_t* pErrorCode);

//Profile Position Mode
int32_t  VCS_ActivateProfilePositionMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetPositionProfile(void* KeyHandle, uint16_t NodeId, uint32_t ProfileVelocity, uint32_t ProfileAcceleration, uint32_t ProfileDeceleration, uint32_t* pErrorCode);
int32_t  VCS_GetPositionProfile(void* KeyHandle, uint16_t NodeId, uint32_t* pProfileVelocity, uint32_t* pProfileAcceleration, uint32_t* pProfileDeceleration, uint32_t* pErrorCode);
int32_t  VCS_MoveToPosition(void* KeyHandle, uint16_t NodeId, long TargetPosition, int32_t Absolute, int32_t Immediately, uint32_t* pErrorCode);
int32_t  VCS_GetTargetPosition(void* KeyHandle, uint16_t NodeId, long* pTargetPosition, uint32_t* pErrorCode);
int32_t  VCS_HaltPositionMovement(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Advanced Functions
int32_t  VCS_EnablePositionWindow(void* KeyHandle, uint16_t NodeId, uint32_t PositionWindow, uint16_t PositionWindowTime, uint32_t* pErrorCode);
int32_t  VCS_DisablePositionWindow(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Profile Velocity Mode
int32_t  VCS_ActivateProfileVelocityMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetVelocityProfile(void* KeyHandle, uint16_t NodeId, uint32_t ProfileAcceleration, uint32_t ProfileDeceleration, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityProfile(void* KeyHandle, uint16_t NodeId, uint32_t* pProfileAcceleration, uint32_t* pProfileDeceleration, uint32_t* pErrorCode);
int32_t  VCS_MoveWithVelocity(void* KeyHandle, uint16_t NodeId, long TargetVelocity, uint32_t* pErrorCode);
int32_t  VCS_GetTargetVelocity(void* KeyHandle, uint16_t NodeId, long* pTargetVelocity, uint32_t* pErrorCode);
int32_t  VCS_HaltVelocityMovement(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Advanced Functions
int32_t  VCS_EnableVelocityWindow(void* KeyHandle, uint16_t NodeId, uint32_t VelocityWindow, uint16_t VelocityWindowTime, uint32_t* pErrorCode);
int32_t  VCS_DisableVelocityWindow(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Homing Mode
int32_t  VCS_ActivateHomingMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetHomingParameter(void* KeyHandle, uint16_t NodeId, uint32_t HomingAcceleration, uint32_t SpeedSwitch, uint32_t SpeedIndex, int32_t HomeOffset, uint16_t CurrentThreshold, int32_t HomePosition, uint32_t* pErrorCode);
int32_t  VCS_GetHomingParameter(void* KeyHandle, uint16_t NodeId, uint32_t* pHomingAcceleration, uint32_t* pSpeedSwitch, uint32_t* pSpeedIndex, int* pHomeOffset, uint16_t* pCurrentThreshold, int* pHomePosition, uint32_t* pErrorCode);
int32_t  VCS_FindHome(void* KeyHandle, uint16_t NodeId, int8_t HomingMethod, uint32_t* pErrorCode);
int32_t  VCS_StopHoming(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_DefinePosition(void* KeyHandle, uint16_t NodeId, int32_t HomePosition, uint32_t* pErrorCode);
int32_t  VCS_WaitForHomingAttained(void* KeyHandle, uint16_t NodeId, int32_t Timeout, uint32_t* pErrorCode);
int32_t  VCS_GetHomingState(void* KeyHandle, uint16_t NodeId, int* pHomingAttained, int* pHomingError, uint32_t* pErrorCode);

//Interpolated Position Mode
int32_t  VCS_ActivateInterpolatedPositionMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetIpmBufferParameter(void* KeyHandle, uint16_t NodeId, uint16_t UnderflowWarningLimit, uint16_t OverflowWarningLimit, uint32_t* pErrorCode);
int32_t  VCS_GetIpmBufferParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pUnderflowWarningLimit, uint16_t* pOverflowWarningLimit, uint32_t* pMaxBufferSize, uint32_t* pErrorCode);
int32_t  VCS_ClearIpmBuffer(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_GetFreeIpmBufferSize(void* KeyHandle, uint16_t NodeId, uint32_t* pBufferSize, uint32_t* pErrorCode);
int32_t  VCS_AddPvtValueToIpmBuffer(void* KeyHandle, uint16_t NodeId, long Position, long Velocity, uint8_t Time, uint32_t* pErrorCode);
int32_t  VCS_StartIpmTrajectory(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_StopIpmTrajectory(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_GetIpmStatus(void* KeyHandle, uint16_t NodeId, int* pTrajectoryRunning, int* pIsUnderflowWarning, int* pIsOverflowWarning, int* pIsVelocityWarning, int* pIsAccelerationWarning, int* pIsUnderflowError, int* pIsOverflowError, int* pIsVelocityError, int* pIsAccelerationError, uint32_t* pErrorCode);

//Position Mode
int32_t  VCS_ActivatePositionMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetPositionMust(void* KeyHandle, uint16_t NodeId, long PositionMust, uint32_t* pErrorCode);
int32_t  VCS_GetPositionMust(void* KeyHandle, uint16_t NodeId, long* pPositionMust, uint32_t* pErrorCode);

//Advanced Functions
int32_t  VCS_ActivateAnalogPositionSetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, float Scaling, long Offset, uint32_t* pErrorCode);
int32_t  VCS_DeactivateAnalogPositionSetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, uint32_t* pErrorCode);
int32_t  VCS_EnableAnalogPositionSetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_DisableAnalogPositionSetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Velocity Mode
int32_t  VCS_ActivateVelocityMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetVelocityMust(void* KeyHandle, uint16_t NodeId, long VelocityMust, uint32_t* pErrorCode);
int32_t  VCS_GetVelocityMust(void* KeyHandle, uint16_t NodeId, long* pVelocityMust, uint32_t* pErrorCode);

//Advanced Functions
int32_t  VCS_ActivateAnalogVelocitySetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, float Scaling, long Offset, uint32_t* pErrorCode);
int32_t  VCS_DeactivateAnalogVelocitySetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, uint32_t* pErrorCode);
int32_t  VCS_EnableAnalogVelocitySetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_DisableAnalogVelocitySetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//Current Mode
int32_t  VCS_ActivateCurrentMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetCurrentMust(void* KeyHandle, uint16_t NodeId, short CurrentMust, uint32_t* pErrorCode);
int32_t  VCS_SetCurrentMustEx(void* KeyHandle, uint16_t NodeId, int32_t CurrentMust, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentMust(void* KeyHandle, uint16_t NodeId, short* pCurrentMust, uint32_t* pErrorCode);
int32_t  VCS_GetCurrentMustEx(void* KeyHandle, uint16_t NodeId, int* pCurrentMust, uint32_t* pErrorCode);

//Advanced Functions
int32_t  VCS_ActivateAnalogCurrentSetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, float Scaling, short Offset, uint32_t* pErrorCode);
int32_t  VCS_DeactivateAnalogCurrentSetpoint(void* KeyHandle, uint16_t NodeId, uint16_t AnalogInputNumber, uint32_t* pErrorCode);
int32_t  VCS_EnableAnalogCurrentSetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_DisableAnalogCurrentSetpoint(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//MasterEncoder Mode
int32_t  VCS_ActivateMasterEncoderMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetMasterEncoderParameter(void* KeyHandle, uint16_t NodeId, uint16_t ScalingNumerator, uint16_t ScalingDenominator, uint8_t Polarity, uint32_t MaxVelocity, uint32_t MaxAcceleration, uint32_t* pErrorCode);
int32_t  VCS_GetMasterEncoderParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pScalingNumerator, uint16_t* pScalingDenominator, unsigned char* pPolarity, uint32_t* pMaxVelocity, uint32_t* pMaxAcceleration, uint32_t* pErrorCode);

//StepDirection Mode
int32_t  VCS_ActivateStepDirectionMode(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetStepDirectionParameter(void* KeyHandle, uint16_t NodeId, uint16_t ScalingNumerator, uint16_t ScalingDenominator, uint8_t Polarity, uint32_t MaxVelocity, uint32_t MaxAcceleration, uint32_t* pErrorCode);
int32_t  VCS_GetStepDirectionParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pScalingNumerator, uint16_t* pScalingDenominator, unsigned char* pPolarity, uint32_t* pMaxVelocity, uint32_t* pMaxAcceleration, uint32_t* pErrorCode);

//Inputs Outputs
//General
int32_t  VCS_GetAllDigitalInputs(void* KeyHandle, uint16_t NodeId, uint16_t* pInputs, uint32_t* pErrorCode);
int32_t  VCS_GetAllDigitalOutputs(void* KeyHandle, uint16_t NodeId, uint16_t* pOutputs, uint32_t* pErrorCode);
int32_t  VCS_SetAllDigitalOutputs(void* KeyHandle, uint16_t NodeId, uint16_t Outputs, uint32_t* pErrorCode);
int32_t  VCS_GetAnalogInput(void* KeyHandle, uint16_t NodeId, uint16_t InputNumber, uint16_t* pAnalogValue, uint32_t* pErrorCode);
int32_t  VCS_GetAnalogInputVoltage(void* KeyHandle, uint16_t NodeId, uint16_t InputNumber, long* pVoltageValue, uint32_t* pErrorCode);
int32_t  VCS_GetAnalogInputState(void* KeyHandle, uint16_t NodeId, uint16_t Configuration, long* pStateValue, uint32_t* pErrorCode);
int32_t  VCS_SetAnalogOutput(void* KeyHandle, uint16_t NodeId, uint16_t OutputNumber, uint16_t AnalogValue, uint32_t* pErrorCode);
int32_t  VCS_SetAnalogOutputVoltage(void* KeyHandle, uint16_t NodeId, uint16_t OutputNumber, long VoltageValue, uint32_t* pErrorCode);
int32_t  VCS_SetAnalogOutputState(void* KeyHandle, uint16_t NodeId, uint16_t Configuration, long StateValue, uint32_t* pErrorCode);

//Position Compare
int32_t  VCS_SetPositionCompareParameter(void* KeyHandle, uint16_t NodeId, uint8_t OperationalMode, uint8_t IntervalMode, uint8_t DirectionDependency, uint16_t IntervalWidth, uint16_t IntervalRepetitions, uint16_t PulseWidth, uint32_t* pErrorCode);
int32_t  VCS_GetPositionCompareParameter(void* KeyHandle, uint16_t NodeId, unsigned char* pOperationalMode, unsigned char* pIntervalMode, unsigned char* pDirectionDependency, uint16_t* pIntervalWidth, uint16_t* pIntervalRepetitions, uint16_t* pPulseWidth, uint32_t* pErrorCode);
int32_t  VCS_ActivatePositionCompare(void* KeyHandle, uint16_t NodeId, uint16_t DigitalOutputNumber, int32_t Polarity, uint32_t* pErrorCode);
int32_t  VCS_DeactivatePositionCompare(void* KeyHandle, uint16_t NodeId, uint16_t DigitalOutputNumber, uint32_t* pErrorCode);
int32_t  VCS_EnablePositionCompare(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_DisablePositionCompare(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t  VCS_SetPositionCompareReferencePosition(void* KeyHandle, uint16_t NodeId, long ReferencePosition, uint32_t* pErrorCode);

//Position Marker
int32_t  VCS_SetPositionMarkerParameter(void* KeyHandle, uint16_t NodeId, uint8_t PositionMarkerEdgeType, uint8_t PositionMarkerMode, uint32_t* pErrorCode);
int32_t  VCS_GetPositionMarkerParameter(void* KeyHandle, uint16_t NodeId, unsigned char* pPositionMarkerEdgeType, unsigned char* pPositionMarkerMode, uint32_t* pErrorCode);
int32_t  VCS_ActivatePositionMarker(void* KeyHandle, uint16_t NodeId, uint16_t DigitalInputNumber, int32_t Polarity, uint32_t* pErrorCode);
int32_t  VCS_DeactivatePositionMarker(void* KeyHandle, uint16_t NodeId, uint16_t DigitalInputNumber, uint32_t* pErrorCode);
int32_t  VCS_ReadPositionMarkerCounter(void* KeyHandle, uint16_t NodeId, uint16_t* pCount, uint32_t* pErrorCode);
int32_t  VCS_ReadPositionMarkerCapturedPosition(void* KeyHandle, uint16_t NodeId, uint16_t CounterIndex, long* pCapturedPosition, uint32_t* pErrorCode);
int32_t  VCS_ResetPositionMarkerCounter(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//*******************************************************************************************************************
// DATA RECORDING FUNCTIONS
//*******************************************************************************************************************

//DataRecorder Setup
int32_t VCS_SetRecorderParameter(void* KeyHandle, uint16_t NodeId, uint16_t SamplingPeriod, uint16_t NbOfPrecedingSamples, uint32_t* pErrorCode);
int32_t VCS_GetRecorderParameter(void* KeyHandle, uint16_t NodeId, uint16_t* pSamplingPeriod, uint16_t* pNbOfPrecedingSamples, uint32_t* pErrorCode);
int32_t VCS_EnableTrigger(void* KeyHandle, uint16_t NodeId, uint8_t TriggerType, uint32_t* pErrorCode);
int32_t VCS_DisableAllTriggers(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t VCS_ActivateChannel(void* KeyHandle, uint16_t NodeId, uint8_t ChannelNumber, uint16_t ObjectIndex, uint8_t ObjectSubIndex, uint8_t ObjectSize, uint32_t* pErrorCode);
int32_t VCS_DeactivateAllChannels(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);

//DataRecorder Status
int32_t VCS_StartRecorder(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t VCS_StopRecorder(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t VCS_ForceTrigger(void* KeyHandle, uint16_t NodeId, uint32_t* pErrorCode);
int32_t VCS_IsRecorderRunning(void* KeyHandle, uint16_t NodeId, int* pRunning, uint32_t* pErrorCode);
int32_t VCS_IsRecorderTriggered(void* KeyHandle, uint16_t NodeId, int* pTriggered, uint32_t* pErrorCode);

//DataRecorder Data
int32_t VCS_ReadChannelVectorSize(void* KeyHandle, uint16_t NodeId, uint32_t* pVectorSize, uint32_t* pErrorCode);
int32_t VCS_ReadChannelDataVector(void* KeyHandle, uint16_t NodeId, uint8_t ChannelNumber, unsigned char* pDataVectorBuffer, uint32_t VectorBufferSize, uint32_t* pErrorCode);

//Advanced Functions
int32_t VCS_ReadDataBuffer(void* KeyHandle, uint16_t NodeId, unsigned char* pDataBuffer, uint32_t BufferSizeToRead, uint32_t* pBufferSizeRead, uint16_t* pVectorStartOffset, uint16_t* pMaxNbOfSamples, uint16_t* pNbOfRecordedSamples, uint32_t* pErrorCode);
int32_t VCS_ExtractChannelDataVector(void* KeyHandle, uint16_t NodeId, uint8_t ChannelNumber, unsigned char* pDataBuffer, uint32_t BufferSize, unsigned char* pDataVector, uint32_t VectorSize, uint16_t VectorStartOffset, uint16_t MaxNbOfSamples, uint16_t NbOfRecordedSamples, uint32_t* pErrorCode);

/*************************************************************************************************************************************
 * LOW LAYER FUNCTIONS
 *************************************************************************************************************************************/

//CanLayer Functions
int32_t  VCS_SendCANFrame(void* KeyHandle, uint16_t CobID, uint16_t Length, void* pData, uint32_t* pErrorCode);
int32_t  VCS_ReadCANFrame(void* KeyHandle, uint16_t CobID, uint16_t Length, void* pData, uint32_t Timeout, uint32_t* pErrorCode);
int32_t  VCS_RequestCANFrame(void* KeyHandle, uint16_t CobID, uint16_t Length, void* pData, uint32_t* pErrorCode);
int32_t  VCS_SendNMTService(void* KeyHandle, uint16_t NodeId, uint16_t CommandSpecifier, uint32_t* pErrorCode);

/*************************************************************************************************************************************
 * TYPE DEFINITIONS
 *************************************************************************************************************************************/
//Communication
//Dialog Mode
const int32_t DM_PROGRESS_DLG                   = 0;
const int32_t DM_PROGRESS_AND_CONFIRM_DLG       = 1;
const int32_t DM_CONFIRM_DLG                    = 2;
const int32_t DM_NO_DLG                         = 3;

//Configuration
//MotorType
const uint16_t MT_DC_MOTOR                      = 1;
const uint16_t MT_EC_SINUS_COMMUTATED_MOTOR     = 10;
const uint16_t MT_EC_BLOCK_COMMUTATED_MOTOR     = 11;

//SensorType
const uint16_t ST_UNKNOWN                       = 0;
const uint16_t ST_INC_ENCODER_3CHANNEL          = 1;
const uint16_t ST_INC_ENCODER_2CHANNEL          = 2;
const uint16_t ST_HALL_SENSORS                  = 3;
const uint16_t ST_SSI_ABS_ENCODER_BINARY        = 4;
const uint16_t ST_SSI_ABS_ENCODER_GREY          = 5;
const uint16_t ST_INC_ENCODER2_3CHANNEL         = 6;
const uint16_t ST_INC_ENCODER2_2CHANNEL         = 7;
const uint16_t ST_ANALOG_INC_ENCODER_3CHANNEL   = 8;
const uint16_t ST_ANALOG_INC_ENCODER_2CHANNEL   = 9;

//In- and outputs
//Digital input configuration
const uint16_t DIC_NEGATIVE_LIMIT_SWITCH        = 0;
const uint16_t DIC_POSITIVE_LIMIT_SWITCH        = 1;
const uint16_t DIC_HOME_SWITCH                  = 2;
const uint16_t DIC_POSITION_MARKER              = 3;
const uint16_t DIC_DRIVE_ENABLE                 = 4;
const uint16_t DIC_QUICK_STOP                   = 5;
const uint16_t DIC_GENERAL_PURPOSE_J            = 6;
const uint16_t DIC_GENERAL_PURPOSE_I            = 7;
const uint16_t DIC_GENERAL_PURPOSE_H            = 8;
const uint16_t DIC_GENERAL_PURPOSE_G            = 9;
const uint16_t DIC_GENERAL_PURPOSE_F            = 10;
const uint16_t DIC_GENERAL_PURPOSE_E            = 11;
const uint16_t DIC_GENERAL_PURPOSE_D            = 12;
const uint16_t DIC_GENERAL_PURPOSE_C            = 13;
const uint16_t DIC_GENERAL_PURPOSE_B            = 14;
const uint16_t DIC_GENERAL_PURPOSE_A            = 15;

//Digital output configuration
const uint16_t DOC_READY_FAULT                  = 0;
const uint16_t DOC_POSITION_COMPARE             = 1;
const uint16_t DOC_GENERAL_PURPOSE_H            = 8;
const uint16_t DOC_GENERAL_PURPOSE_G            = 9;
const uint16_t DOC_GENERAL_PURPOSE_F            = 10;
const uint16_t DOC_GENERAL_PURPOSE_E            = 11;
const uint16_t DOC_GENERAL_PURPOSE_D            = 12;
const uint16_t DOC_GENERAL_PURPOSE_C            = 13;
const uint16_t DOC_GENERAL_PURPOSE_B            = 14;
const uint16_t DOC_GENERAL_PURPOSE_A            = 15;

//Analog input configuration
const uint16_t AIC_ANALOG_CURRENT_SETPOint32_t      = 0;
const uint16_t AIC_ANALOG_VELOCITY_SETPOint32_t     = 1;
const uint16_t AIC_ANALOG_POSITION_SETPOint32_t     = 2;
const uint16_t AIC_GENERAL_PURPOSE_H            = 8;
const uint16_t AIC_GENERAL_PURPOSE_G            = 9;
const uint16_t AIC_GENERAL_PURPOSE_F            = 10;
const uint16_t AIC_GENERAL_PURPOSE_E            = 11;
const uint16_t AIC_GENERAL_PURPOSE_D            = 12;
const uint16_t AIC_GENERAL_PURPOSE_C            = 13;
const uint16_t AIC_GENERAL_PURPOSE_B            = 14;
const uint16_t AIC_GENERAL_PURPOSE_A            = 15;

//Analog output configuration
const uint16_t AOC_GENERAL_PURPOSE_A            = 0;
const uint16_t AOC_GENERAL_PURPOSE_B            = 1;

//Units
//VelocityDimension
const uint8_t VD_RPM                            = 0xA4;

//VelocityNotation
const int8_t VN_STANDARD                         = 0;
const int8_t VN_DECI                             = -1;
const int8_t VN_CENTI                            = -2;
const int8_t VN_MILLI                            = -3;

//Operational mode
const int8_t OMD_PROFILE_POSITION_MODE          = 1;
const int8_t OMD_PROFILE_VELOCITY_MODE          = 3;
const int8_t OMD_HOMING_MODE                    = 6;
const int8_t OMD_INTERPOLATED_POSITION_MODE     = 7;
const int8_t OMD_POSITION_MODE                  = -1;
const int8_t OMD_VELOCITY_MODE                  = -2;
const int8_t OMD_CURRENT_MODE                   = -3;
const int8_t OMD_MASTER_ENCODER_MODE            = -5;
const int8_t OMD_STEP_DIRECTION_MODE            = -6;

//States
const uint16_t ST_DISABLED                         = 0;
const uint16_t ST_ENABLED                          = 1;
const uint16_t ST_QUICKSTOP                        = 2;
const uint16_t ST_FAULT                            = 3;

//Homing mode
//Homing method
const int8_t HM_ACTUAL_POSITION                               = 35;
const int8_t HM_NEGATIVE_LIMIT_SWITCH                         = 17;
const int8_t HM_NEGATIVE_LIMIT_SWITCH_AND_INDEX               = 1;
const int8_t HM_POSITIVE_LIMIT_SWITCH                         = 18;
const int8_t HM_POSITIVE_LIMIT_SWITCH_AND_INDEX               = 2;
const int8_t HM_HOME_SWITCH_POSITIVE_SPEED                    = 23;
const int8_t HM_HOME_SWITCH_POSITIVE_SPEED_AND_INDEX          = 7;
const int8_t HM_HOME_SWITCH_NEGATIVE_SPEED                    = 27;
const int8_t HM_HOME_SWITCH_NEGATIVE_SPEED_AND_INDEX          = 11;
const int8_t HM_CURRENT_THRESHOLD_POSITIVE_SPEED              = -3;
const int8_t HM_CURRENT_THRESHOLD_POSITIVE_SPEED_AND_INDEX    = -1;
const int8_t HM_CURRENT_THRESHOLD_NEGATIVE_SPEED              = -4;
const int8_t HM_CURRENT_THRESHOLD_NEGATIVE_SPEED_AND_INDEX    = -2;
const int8_t HM_INDEX_POSITIVE_SPEED                          = 34;
const int8_t HM_INDEX_NEGATIVE_SPEED                          = 33;

//Input Output PositionMarker
//PositionMarkerEdgeType
const uint8_t PET_BOTH_EDGES                   = 0;
const uint8_t PET_RISING_EDGE                  = 1;
const uint8_t PET_FALLING_EDGE                 = 2;

//PositionMarkerMode
const uint8_t PM_CONTINUOUS                    = 0;
const uint8_t PM_SINGLE                        = 1;
const uint8_t PM_MULTIPLE                      = 2;

//Input Output PositionCompare
//PositionCompareOperationalMode
const uint8_t PCO_SINGLE_POSITION_MODE         = 0;
const uint8_t PCO_POSITION_SEQUENCE_MODE       = 1;

//PositionCompareIntervalMode
const uint8_t PCI_NEGATIVE_DIR_TO_REFPOS       = 0;
const uint8_t PCI_POSITIVE_DIR_TO_REFPOS       = 1;
const uint8_t PCI_BOTH_DIR_TO_REFPOS           = 2;

//PositionCompareDirectionDependency
const uint8_t PCD_MOTOR_DIRECTION_NEGATIVE     = 0;
const uint8_t PCD_MOTOR_DIRECTION_POSITIVE     = 1;
const uint8_t PCD_MOTOR_DIRECTION_BOTH         = 2;

//Data recorder
//Trigger type
const uint16_t DR_MOVEMENT_START_TRIGGER        = 1;    //bit 1
const uint16_t DR_ERROR_TRIGGER                 = 2;    //bit 2
const uint16_t DR_DIGITAL_INPUT_TRIGGER         = 4;    //bit 3
const uint16_t DR_MOVEMENT_END_TRIGGER          = 8;    //bit 4

//CanLayer Functions
const uint16_t NCS_START_REMOTE_NODE            = 1;
const uint16_t NCS_STOP_REMOTE_NODE             = 2;
const uint16_t NCS_ENTER_PRE_OPERATIONAL        = 128;
const uint16_t NCS_RESET_NODE                   = 129;
const uint16_t NCS_RESET_COMMUNICATION          = 130;

// Controller Gains
// EController
const uint16_t EC_PI_CURRENT_CONTROLLER                   = 1;
const uint16_t EC_PI_VELOCITY_CONTROLLER                  = 10;
const uint16_t EC_PI_VELOCITY_CONTROLLER_WITH_OBSERVER    = 11;
const uint16_t EC_PID_POSITION_CONTROLLER                 = 20;
const uint16_t EC_DUAL_LOOP_POSITION_CONTROLLER           = 21;

// EGain (EC_PI_CURRENT_CONTROLLER)
const uint16_t EG_PICC_P_GAIN                             = 1;
const uint16_t EG_PICC_I_GAIN                             = 2;

// EGain (EC_PI_VELOCITY_CONTROLLER)
const uint16_t EG_PIVC_P_GAIN                             = 1;
const uint16_t EG_PIVC_I_GAIN                             = 2;
const uint16_t EG_PIVC_FEED_FORWARD_VELOCITY_GAIN         = 10;
const uint16_t EG_PIVC_FEED_FORWARD_ACCELERATION_GAIN     = 11;

// EGain (EC_PI_VELOCITY_CONTROLLER_WITH_OBSERVER)
const uint16_t EG_PIVCWO_P_GAIN                           = 1;
const uint16_t EG_PIVCWO_I_GAIN                           = 2;
const uint16_t EG_PIVCWO_FEED_FORWARD_VELOCITY_GAIN       = 10;
const uint16_t EG_PIVCWO_FEED_FORWARD_ACCELERATION_GAIN   = 11;
const uint16_t EG_PIVCWO_OBSERVER_THETA_GAIN              = 20;
const uint16_t EG_PIVCWO_OBSERVER_OMEGA_GAIN              = 21;
const uint16_t EG_PIVCWO_OBSERVER_TAU_GAIN                = 22;

// EGain (EC_PID_POSITION_CONTROLLER)
const uint16_t EG_PIDPC_P_GAIN                            = 1;
const uint16_t EG_PIDPC_I_GAIN                            = 2;
const uint16_t EG_PIDPC_D_GAIN                            = 3;
const uint16_t EG_PIDPC_FEED_FORWARD_VELOCITY_GAIN        = 10;
const uint16_t EG_PIDPC_FEED_FORWARD_ACCELERATION_GAIN    = 11;

// EGain (EC_DUAL_LOOP_POSITION_CONTROLLER)
const uint16_t EG_DLPC_AUXILIARY_LOOP_P_GAIN                          = 1;
const uint16_t EG_DLPC_AUXILIARY_LOOP_I_GAIN                          = 2;
const uint16_t EG_DLPC_AUXILIARY_LOOP_FEED_FORWARD_VELOCITY_GAIN      = 10;
const uint16_t EG_DLPC_AUXILIARY_LOOP_FEED_FORWARD_ACCELERATION_GAIN  = 11;
const uint16_t EG_DLPC_AUXILIARY_LOOP_OBSERVER_THETA_GAIN             = 20;
const uint16_t EG_DLPC_AUXILIARY_LOOP_OBSERVER_OMEGA_GAIN             = 21;
const uint16_t EG_DLPC_AUXILIARY_LOOP_OBSERVER_TAU_GAIN               = 22;
const uint16_t EG_DLPC_MAIN_LOOP_P_GAIN_LOW                           = 101;
const uint16_t EG_DLPC_MAIN_LOOP_P_GAIN_HIGH                          = 102;
const uint16_t EG_DLPC_MAIN_LOOP_GAIN_SCHEDULING_WEIGHT               = 110;
const uint16_t EG_DLPC_MAIN_LOOP_FILTER_COEFFICIENT_A                 = 120;
const uint16_t EG_DLPC_MAIN_LOOP_FILTER_COEFFICIENT_B                 = 121;
const uint16_t EG_DLPC_MAIN_LOOP_FILTER_COEFFICIENT_C                 = 122;
const uint16_t EG_DLPC_MAIN_LOOP_FILTER_COEFFICIENT_D                 = 123;
const uint16_t EG_DLPC_MAIN_LOOP_FILTER_COEFFICIENT_E                 = 124;

#endif //_H_LINUX_EPOSCMD_

