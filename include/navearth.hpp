/*
** navearth.hpp for mscnav in /home/fwt/myprogram/mscnav/submodules/tools/include
**
** Made by little fang
** Login   <fangwentao>
**
** Started on  Thu Jul 11 下午7:17:43 2019 little fang
** Last update Sun Jul 13 上午6:26:32 2019 little fang
*/

#ifndef UTIL_EARTH_H_
#define UTIL_EARTH_H_

#include "constant.hpp"
#include <Eigen/Dense>

namespace utiltool
{
namespace earth
{
using constant::constant_J2;
using constant::constant_J4;
using constant::constant_J6;
using constant::WGS84_A;
using constant::WGS84_AngleRate;
using constant::WGS84_GM;
using Eigen::Vector3d;

template <typename T>
inline T POW3(const T &t)
{
    return t * t * t;
}

Vector3d CalculateGravity(const Vector3d &pos, bool IsECEF = true);

/**
  * @brief  BLH coordinate convert to rectangle XYZ in WGS84 coordinate
  * @note   
  * @param  &BLH: [rad rad m]
  * @retval 
  */
Eigen::Vector3d WGS84BLH2XYZ(const Eigen::Vector3d &BLH);

/**
  * @brief  XYZ coordinate convert to BLH in WGS84 coordinate
  * @note   
  * @param  &XYZ: [m,m,m]
  * @retval 
  */
Eigen::Vector3d WGS84XYZ2BLH(const Eigen::Vector3d &XYZ);

/**
 * @brief  calculate the rotation matrix of n coordinate to ecef
 * @note   
 * @param  B: 
 * @param  L: 
 * @retval 
 */
Eigen::Matrix3d CalCn2e(double B, double L);

/**
 * @brief  calculate the rotation matrix of ecef coordinate to navigation(local coordinate)
 * @note   
 * @param  B: 
 * @param  L: 
 * @retval 
 */
Eigen::Matrix3d CalCe2n(double B, double L);

inline Eigen::Vector3d wiee() { return Eigen::Vector3d(0, 0, WGS84_AngleRate); }

} // namespace earth
} // namespace utiltool

#endif /* !UTIL_EARTH_H_ */