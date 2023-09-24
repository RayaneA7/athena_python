#include <tiramisu/tiramisu.h> 
#include <tiramisu/auto_scheduler/evaluator.h>
#include <tiramisu/auto_scheduler/search_method.h>
#include "function800111_wrapper.h"

using namespace tiramisu;

int main(int argc, char **argv){                
	tiramisu::init("function800111");
	var i0("i0", 0, 384), i1("i1", 1, 385), i2("i2", 0, 384), i3("i3", 1, 385), i1_p1("i1_p1", 0, 386), i3_p1("i3_p1", 0, 386);
	input input01("input01", {i1_p1,i2}, p_float64);
	input input02("input02", {i0}, p_float64);
	input input04("input04", {i3_p1}, p_float64);
	computation comp00("comp00", {i0,i1,i2}, expr(0.0) - input02(i0)/input01(i1 - 1, i2) + input01(i1 + 1, i2)/input01(i1, i2));
	computation comp01("comp01", {i0,i1,i3}, expr(25.009)*input04(i3)*input04(i3 - 1)*input04(i3 + 1));
	comp00.then(comp01, i1);
	buffer buf00("buf00", {385,384}, p_float64, a_output);
	buffer buf01("buf01", {386,384}, p_float64, a_input);
	buffer buf02("buf02", {384}, p_float64, a_input);
	buffer buf03("buf03", {384,385}, p_float64, a_output);
	buffer buf04("buf04", {386}, p_float64, a_input);
	input01.store_in(&buf01);
	input02.store_in(&buf02);
	input04.store_in(&buf04);
	comp00.store_in(&buf00, {i1,i2});
	comp01.store_in(&buf03, {i0,i1});
	tiramisu::codegen({&buf00,&buf01,&buf02,&buf03,&buf04}, "function800111.o"); 
	return 0; 
}