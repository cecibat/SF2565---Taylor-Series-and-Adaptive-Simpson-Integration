clc; clear all; close all;

% This short code is used to get the value of the integral of f(x) = (1 +
% sin(e^(3x)) between the interval [a,b]=[-1,1]. The value is obtained
% using the "integral" inbuilt MATLAB function. The relative tolerance is
% set to 10^(-8). It is chosen to set the relative tolerance to this
% bounding value since it is a measure of the error relative to the size of
% each component solution.



% Format long is chosen to get all the digits and let comparisons be more
% punctual and precise.

f = @(x) (1 + sin(exp(3*x)));
format long;
q = integral(f, -1, 1, 'AbsTol',1e-8)