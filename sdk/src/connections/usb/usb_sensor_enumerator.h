/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, Analog Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef USB_SENSOR_ENUMERATOR_H
#define USB_SENSOR_ENUMERATOR_H

#include "aditof/sensor_enumerator_interface.h"
#include "usb_buffer.pb.h"

class UsbSensorEnumerator : public aditof::SensorEnumeratorInterface {
  public:
    ~UsbSensorEnumerator();

  public: // implements SensorEnumeratorInterface
    virtual aditof::Status searchSensors() override;
    virtual aditof::Status
    getDepthSensors(std::vector<std::shared_ptr<aditof::DepthSensorInterface>>
                        &depthSensors) override;
    virtual aditof::Status getStorages(
        std::vector<std::shared_ptr<aditof::StorageInterface>> &storages)
        override;
    virtual aditof::Status getTemperatureSensors(
        std::vector<std::shared_ptr<aditof::TemperatureSensorInterface>>
            &temperatureSensors) override;

    virtual aditof::Status
    getUbootVersion(std::string &uBootVersion) const override;
    virtual aditof::Status
    getKernelVersion(std::string &kernelVersion) const override;
    virtual aditof::Status getSdVersion(std::string &sdVersion) const override;

  private:
    struct SensorInfo {
        std::string driverPath;
    };
    std::string m_sensorName;

    int fd;

    std::vector<SensorInfo> m_sensorsInfo;
    std::vector<std::pair<std::string, unsigned int>> m_storagesInfo;
    std::vector<std::pair<std::string, unsigned int>> m_temperatureSensorsInfo;
    std::string m_uBootVersion;
    std::string m_kernelVersion;
    std::string m_sdVersion;
};

#endif // USB_SENSOR_ENUMERATOR_H
