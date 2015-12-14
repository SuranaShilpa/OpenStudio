/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "SurfacePropertyOtherSideCoefficients.hpp"
#include "SurfacePropertyOtherSideCoefficients_Impl.hpp"

// TODO: Check the following class names against object getters and setters.
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "../../model/ScheduleTypeLimits.hpp"
#include "../../model/ScheduleTypeRegistry.hpp"

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_SurfaceProperty_OtherSideCoefficients_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  SurfacePropertyOtherSideCoefficients_Impl::SurfacePropertyOtherSideCoefficients_Impl(const IdfObject& idfObject,
                                                                                       Model_Impl* model,
                                                                                       bool keepHandle)
    : ResourceObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SurfacePropertyOtherSideCoefficients::iddObjectType());
  }

  SurfacePropertyOtherSideCoefficients_Impl::SurfacePropertyOtherSideCoefficients_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                       Model_Impl* model,
                                                                                       bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SurfacePropertyOtherSideCoefficients::iddObjectType());
  }

  SurfacePropertyOtherSideCoefficients_Impl::SurfacePropertyOtherSideCoefficients_Impl(const SurfacePropertyOtherSideCoefficients_Impl& other,
                                                                                       Model_Impl* model,
                                                                                       bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SurfacePropertyOtherSideCoefficients_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SurfacePropertyOtherSideCoefficients_Impl::iddObjectType() const {
    return SurfacePropertyOtherSideCoefficients::iddObjectType();
  }

  std::vector<ScheduleTypeKey> SurfacePropertyOtherSideCoefficients_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SurfacePropertyOtherSideCoefficients","Constant Temperature"));
    }
    return result;
  }

  double SurfacePropertyOtherSideCoefficients_Impl::combinedConvectiveRadiativeFilmCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::CombinedConvective_RadiativeFilmCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  double SurfacePropertyOtherSideCoefficients_Impl::constantTemperature() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isConstantTemperatureDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperature);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::constantTemperatureCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isConstantTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureCoefficient);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::externalDryBulbTemperatureCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ExternalDryBulbTemperatureCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isExternalDryBulbTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::ExternalDryBulbTemperatureCoefficient);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::groundTemperatureCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::GroundTemperatureCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isGroundTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::GroundTemperatureCoefficient);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::windSpeedCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::WindSpeedCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isWindSpeedCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::WindSpeedCoefficient);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::zoneAirTemperatureCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ZoneAirTemperatureCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isZoneAirTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::ZoneAirTemperatureCoefficient);
  }

  boost::optional<Schedule> SurfacePropertyOtherSideCoefficients_Impl::constantTemperatureSchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureScheduleName);
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::sinusoidalVariationofConstantTemperatureCoefficient() const {
    boost::optional<std::string> value = getString(OS_SurfaceProperty_OtherSideCoefficientsFields::SinusoidalVariationofConstantTemperatureCoefficient,true);
    OS_ASSERT(value);
    return openstudio::istringEqual(value.get(), "Yes");
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isSinusoidalVariationofConstantTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::SinusoidalVariationofConstantTemperatureCoefficient);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::periodofSinusoidalVariation() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::PeriodofSinusoidalVariation,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isPeriodofSinusoidalVariationDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::PeriodofSinusoidalVariation);
  }

  double SurfacePropertyOtherSideCoefficients_Impl::previousOtherSideTemperatureCoefficient() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::PreviousOtherSideTemperatureCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::isPreviousOtherSideTemperatureCoefficientDefaulted() const {
    return isEmpty(OS_SurfaceProperty_OtherSideCoefficientsFields::PreviousOtherSideTemperatureCoefficient);
  }

  boost::optional<double> SurfacePropertyOtherSideCoefficients_Impl::minimumOtherSideTemperatureLimit() const {
    return getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::MinimumOtherSideTemperatureLimit,true);
  }

  boost::optional<double> SurfacePropertyOtherSideCoefficients_Impl::maximumOtherSideTemperatureLimit() const {
    return getDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::MaximumOtherSideTemperatureLimit,true);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setCombinedConvectiveRadiativeFilmCoefficient(double combinedConvectiveRadiativeFilmCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::CombinedConvective_RadiativeFilmCoefficient, combinedConvectiveRadiativeFilmCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setConstantTemperature(double constantTemperature) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperature, constantTemperature);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetConstantTemperature() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperature, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setConstantTemperatureCoefficient(double constantTemperatureCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureCoefficient, constantTemperatureCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetConstantTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setExternalDryBulbTemperatureCoefficient(double externalDryBulbTemperatureCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ExternalDryBulbTemperatureCoefficient, externalDryBulbTemperatureCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetExternalDryBulbTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::ExternalDryBulbTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setGroundTemperatureCoefficient(double groundTemperatureCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::GroundTemperatureCoefficient, groundTemperatureCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetGroundTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::GroundTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setWindSpeedCoefficient(double windSpeedCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::WindSpeedCoefficient, windSpeedCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetWindSpeedCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::WindSpeedCoefficient, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setZoneAirTemperatureCoefficient(double zoneAirTemperatureCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::ZoneAirTemperatureCoefficient, zoneAirTemperatureCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetZoneAirTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::ZoneAirTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::setConstantTemperatureSchedule(Schedule& schedule) {
    bool result = setSchedule(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureScheduleName,
                              "SurfacePropertyOtherSideCoefficients",
                              "Constant Temperature",
                              schedule);
    return result;
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetConstantTemperatureSchedule() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::ConstantTemperatureScheduleName, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setSinusoidalVariationofConstantTemperatureCoefficient(bool sinusoidalVariationofConstantTemperatureCoefficient) {
    bool result = false;
    if (sinusoidalVariationofConstantTemperatureCoefficient) {
      result = setBooleanFieldValue(OS_SurfaceProperty_OtherSideCoefficientsFields::SinusoidalVariationofConstantTemperatureCoefficient, "Yes");
    } else {
      result = setBooleanFieldValue(OS_SurfaceProperty_OtherSideCoefficientsFields::SinusoidalVariationofConstantTemperatureCoefficient, "No");
    }
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetSinusoidalVariationofConstantTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::SinusoidalVariationofConstantTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyOtherSideCoefficients_Impl::setPeriodofSinusoidalVariation(double periodofSinusoidalVariation) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::PeriodofSinusoidalVariation, periodofSinusoidalVariation);
    return result;
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetPeriodofSinusoidalVariation() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::PeriodofSinusoidalVariation, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setPreviousOtherSideTemperatureCoefficient(double previousOtherSideTemperatureCoefficient) {
    bool result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::PreviousOtherSideTemperatureCoefficient, previousOtherSideTemperatureCoefficient);
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetPreviousOtherSideTemperatureCoefficient() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::PreviousOtherSideTemperatureCoefficient, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setMinimumOtherSideTemperatureLimit(boost::optional<double> minimumOtherSideTemperatureLimit) {
    bool result(false);
    if (minimumOtherSideTemperatureLimit) {
      result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::MinimumOtherSideTemperatureLimit, minimumOtherSideTemperatureLimit.get());
    }
    else {
      resetMinimumOtherSideTemperatureLimit();
      result = true;
    }
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetMinimumOtherSideTemperatureLimit() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::MinimumOtherSideTemperatureLimit, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::setMaximumOtherSideTemperatureLimit(boost::optional<double> maximumOtherSideTemperatureLimit) {
    bool result(false);
    if (maximumOtherSideTemperatureLimit) {
      result = setDouble(OS_SurfaceProperty_OtherSideCoefficientsFields::MaximumOtherSideTemperatureLimit, maximumOtherSideTemperatureLimit.get());
    }
    else {
      resetMaximumOtherSideTemperatureLimit();
      result = true;
    }
    OS_ASSERT(result);
  }

  void SurfacePropertyOtherSideCoefficients_Impl::resetMaximumOtherSideTemperatureLimit() {
    bool result = setString(OS_SurfaceProperty_OtherSideCoefficientsFields::MaximumOtherSideTemperatureLimit, "");
    OS_ASSERT(result);
  }

} // detail

SurfacePropertyOtherSideCoefficients::SurfacePropertyOtherSideCoefficients(const Model& model)
  : ResourceObject(SurfacePropertyOtherSideCoefficients::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
  // setCombinedConvectiveRadiativeFilmCoefficient();
}

IddObjectType SurfacePropertyOtherSideCoefficients::iddObjectType() {
  return IddObjectType(IddObjectType::OS_SurfaceProperty_OtherSideCoefficients);
}

double SurfacePropertyOtherSideCoefficients::combinedConvectiveRadiativeFilmCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->combinedConvectiveRadiativeFilmCoefficient();
}

double SurfacePropertyOtherSideCoefficients::constantTemperature() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->constantTemperature();
}

bool SurfacePropertyOtherSideCoefficients::isConstantTemperatureDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isConstantTemperatureDefaulted();
}

double SurfacePropertyOtherSideCoefficients::constantTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->constantTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isConstantTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isConstantTemperatureCoefficientDefaulted();
}

double SurfacePropertyOtherSideCoefficients::externalDryBulbTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->externalDryBulbTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isExternalDryBulbTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isExternalDryBulbTemperatureCoefficientDefaulted();
}

double SurfacePropertyOtherSideCoefficients::groundTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->groundTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isGroundTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isGroundTemperatureCoefficientDefaulted();
}

double SurfacePropertyOtherSideCoefficients::windSpeedCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->windSpeedCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isWindSpeedCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isWindSpeedCoefficientDefaulted();
}

double SurfacePropertyOtherSideCoefficients::zoneAirTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->zoneAirTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isZoneAirTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isZoneAirTemperatureCoefficientDefaulted();
}

boost::optional<Schedule> SurfacePropertyOtherSideCoefficients::constantTemperatureSchedule() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->constantTemperatureSchedule();
}

bool SurfacePropertyOtherSideCoefficients::sinusoidalVariationofConstantTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->sinusoidalVariationofConstantTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isSinusoidalVariationofConstantTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isSinusoidalVariationofConstantTemperatureCoefficientDefaulted();
}

double SurfacePropertyOtherSideCoefficients::periodofSinusoidalVariation() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->periodofSinusoidalVariation();
}

bool SurfacePropertyOtherSideCoefficients::isPeriodofSinusoidalVariationDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isPeriodofSinusoidalVariationDefaulted();
}

double SurfacePropertyOtherSideCoefficients::previousOtherSideTemperatureCoefficient() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->previousOtherSideTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::isPreviousOtherSideTemperatureCoefficientDefaulted() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->isPreviousOtherSideTemperatureCoefficientDefaulted();
}

boost::optional<double> SurfacePropertyOtherSideCoefficients::minimumOtherSideTemperatureLimit() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->minimumOtherSideTemperatureLimit();
}

boost::optional<double> SurfacePropertyOtherSideCoefficients::maximumOtherSideTemperatureLimit() const {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->maximumOtherSideTemperatureLimit();
}

void SurfacePropertyOtherSideCoefficients::setCombinedConvectiveRadiativeFilmCoefficient(double combinedConvectiveRadiativeFilmCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setCombinedConvectiveRadiativeFilmCoefficient(combinedConvectiveRadiativeFilmCoefficient);
}

void SurfacePropertyOtherSideCoefficients::setConstantTemperature(double constantTemperature) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setConstantTemperature(constantTemperature);
}

void SurfacePropertyOtherSideCoefficients::resetConstantTemperature() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetConstantTemperature();
}

void SurfacePropertyOtherSideCoefficients::setConstantTemperatureCoefficient(double constantTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setConstantTemperatureCoefficient(constantTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetConstantTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetConstantTemperatureCoefficient();
}

void SurfacePropertyOtherSideCoefficients::setExternalDryBulbTemperatureCoefficient(double externalDryBulbTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setExternalDryBulbTemperatureCoefficient(externalDryBulbTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetExternalDryBulbTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetExternalDryBulbTemperatureCoefficient();
}

void SurfacePropertyOtherSideCoefficients::setGroundTemperatureCoefficient(double groundTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setGroundTemperatureCoefficient(groundTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetGroundTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetGroundTemperatureCoefficient();
}

void SurfacePropertyOtherSideCoefficients::setWindSpeedCoefficient(double windSpeedCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setWindSpeedCoefficient(windSpeedCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetWindSpeedCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetWindSpeedCoefficient();
}

void SurfacePropertyOtherSideCoefficients::setZoneAirTemperatureCoefficient(double zoneAirTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setZoneAirTemperatureCoefficient(zoneAirTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetZoneAirTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetZoneAirTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::setConstantTemperatureSchedule(Schedule& schedule) {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setConstantTemperatureSchedule(schedule);
}

void SurfacePropertyOtherSideCoefficients::resetConstantTemperatureSchedule() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetConstantTemperatureSchedule();
}

void SurfacePropertyOtherSideCoefficients::setSinusoidalVariationofConstantTemperatureCoefficient(bool sinusoidalVariationofConstantTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setSinusoidalVariationofConstantTemperatureCoefficient(sinusoidalVariationofConstantTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetSinusoidalVariationofConstantTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetSinusoidalVariationofConstantTemperatureCoefficient();
}

bool SurfacePropertyOtherSideCoefficients::setPeriodofSinusoidalVariation(double periodofSinusoidalVariation) {
  return getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setPeriodofSinusoidalVariation(periodofSinusoidalVariation);
}

void SurfacePropertyOtherSideCoefficients::resetPeriodofSinusoidalVariation() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetPeriodofSinusoidalVariation();
}

void SurfacePropertyOtherSideCoefficients::setPreviousOtherSideTemperatureCoefficient(double previousOtherSideTemperatureCoefficient) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setPreviousOtherSideTemperatureCoefficient(previousOtherSideTemperatureCoefficient);
}

void SurfacePropertyOtherSideCoefficients::resetPreviousOtherSideTemperatureCoefficient() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetPreviousOtherSideTemperatureCoefficient();
}

void SurfacePropertyOtherSideCoefficients::setMinimumOtherSideTemperatureLimit(double minimumOtherSideTemperatureLimit) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setMinimumOtherSideTemperatureLimit(minimumOtherSideTemperatureLimit);
}

void SurfacePropertyOtherSideCoefficients::resetMinimumOtherSideTemperatureLimit() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetMinimumOtherSideTemperatureLimit();
}

void SurfacePropertyOtherSideCoefficients::setMaximumOtherSideTemperatureLimit(double maximumOtherSideTemperatureLimit) {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->setMaximumOtherSideTemperatureLimit(maximumOtherSideTemperatureLimit);
}

void SurfacePropertyOtherSideCoefficients::resetMaximumOtherSideTemperatureLimit() {
  getImpl<detail::SurfacePropertyOtherSideCoefficients_Impl>()->resetMaximumOtherSideTemperatureLimit();
}

/// @cond
SurfacePropertyOtherSideCoefficients::SurfacePropertyOtherSideCoefficients(std::shared_ptr<detail::SurfacePropertyOtherSideCoefficients_Impl> impl)
  : ResourceObject(impl)
{}
/// @endcond

} // model
} // openstudio

