#pragma once
#ifndef TEMPREG_H
#define TEMPREG_H

#include <Eigen/Dense>
#include <iostream>

template <typename Derived>
void print_size(const Eigen::EigenBase<Derived> &b) {
  std::cout << "size (rows, cols): " << b.size() << " (" << b.rows() << ", "
            << b.cols() << ")" << std::endl;
}

template <typename M, typename V>
Eigen::MatrixXf regress(const Eigen::MatrixBase<M> &X,
                        const Eigen::MatrixBase<V> &points) {
  // Solve OLS with SVD
  Eigen::JacobiSVD<Eigen::MatrixXf> svd;
  svd.compute(X, Eigen::ComputeThinV | Eigen::ComputeThinU);
  return svd.solve(points);
}

#endif // TEMPREG_H
