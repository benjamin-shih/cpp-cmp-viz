#include <iostream>
#include "mlpack/methods/linear_regression.hpp"

void regress(arma::mat data, arma::vec responses, arma::mat points,
             arma::rowvec predictions) {
  mlpack::LinearRegression lr(data, responses);
  lr.Parameters();
  // lr.Predict(points, predictions);
  // std::cout << predictions << std::endl;
}
