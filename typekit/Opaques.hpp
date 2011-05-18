/* Generated from orogen/lib/orogen/templates/typekit/Opaques.hpp */

#ifndef __OROGEN_GENERATED_base_USER_MARSHALLING_HH
#define __OROGEN_GENERATED_base_USER_MARSHALLING_HH

#include <base/Types.hpp>

namespace orogen_typekits
{
    template<typename T, int ROWS, int COLS, int EIGEN_OPTIONS, int EIGEN_MAX_ROWS, int EIGEN_MAX_COLS>
    void toIntermediate(wrappers::Matrix<T, ROWS, COLS>& intermediate, Eigen::Matrix<T, ROWS, COLS, EIGEN_OPTIONS, EIGEN_MAX_ROWS, EIGEN_MAX_COLS> const& real)
    {
        for(int i=0; i < ROWS*COLS; ++i)
            intermediate.data[i] = real(i / COLS, i % COLS);
    }

    template<typename T, int ROWS, int COLS, int EIGEN_OPTIONS, int EIGEN_MAX_ROWS, int EIGEN_MAX_COLS>
    void fromIntermediate(Eigen::Matrix<T, ROWS, COLS, EIGEN_OPTIONS, EIGEN_MAX_ROWS, EIGEN_MAX_COLS>& real, wrappers::Matrix<T, ROWS, COLS> const& intermediate)
    {
        for(int i=0; i < ROWS*COLS; ++i)
            real(i / COLS, i % COLS) = intermediate.data[i];
    }


    template<typename T, int EIGEN_OPTIONS>
    void toIntermediate(::wrappers::Quaternion<T>& intermediate, ::Eigen::Quaternion<T, EIGEN_OPTIONS> const& real)
    {
        intermediate.re = real.w();
        intermediate.im[0] = real.x();
        intermediate.im[1] = real.y();
        intermediate.im[2] = real.z();
    }

    template<typename T, int EIGEN_OPTIONS>
    void fromIntermediate(::Eigen::Quaternion<T, EIGEN_OPTIONS>& real, ::wrappers::Quaternion<T> const& intermediate)
    {
        real.w() = intermediate.re;
        real.x() = intermediate.im[0];
        real.y() = intermediate.im[1];
        real.z() = intermediate.im[2];
    }

    void toIntermediate(::wrappers::geometry::Spline& intermediate, ::base::geometry::SplineBase const& real_type);

    void fromIntermediate(::base::geometry::SplineBase& real_type, ::wrappers::geometry::Spline const& intermediate);
}

#endif

