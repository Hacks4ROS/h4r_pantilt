#ifndef PANTILTJOY_H_
#define PANTILTJOY_H_

#include <ros/ros.h>
#include <geometry_msgs/Quaternion.h>
#include <sensor_msgs/Joy.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <tf/tf.h>

namespace pan_tilt_adapter {

class PanTiltJoy {
private:

	ros::NodeHandle n;
	ros::NodeHandle nh;

	ros::Subscriber sub_joy;
	ros::Publisher pub_quat;

	int loop_rate;

	bool pan_invert;
	bool tilt_invert;

	int pan_min, pan_max;
	int tilt_min, tilt_max;

	int tilt_home, pan_home;

	int axis_pan,
		axis_tilt;

	bool is_button_axis;

	int button_pan_up,
	    button_pan_down,
	    button_tilt_up,
		button_tilt_down,
		button_reset_lock;

	bool button_pan_up_pressed,
		 button_pan_down_pressed,
	     button_tilt_up_pressed,
		 button_tilt_down_pressed,
		 button_reset_pressed;

	bool lock_is_switch;
	bool locked;
	bool toggle_switch;



    int tilt, pan;
	int b_rate;

	boost::mutex mutexPanTilt, mutex_buttons;


	void workerButton();
	void JoyCallback(const sensor_msgs::Joy::ConstPtr& msg);
	void publish();

public:
	PanTiltJoy();
	virtual ~PanTiltJoy();
	void run();
};

} /* namespace pan_tilt_adapter */

#endif /* h4r_pantilt_adapter_SRC_PANTILTJOY_H_ */
