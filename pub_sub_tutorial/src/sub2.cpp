#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback ( const std_msgs::String::ConstPtr &msg )
{
    if (msg->data.substr(0, 5) == "Hello")
	{
		ROS_INFO ( "Publisher said:\n%s", msg->data.c_str() );
	}
	else 
	{
		ROS_INFO ( "Publisher didn't say something in English...");
	}
}

int main ( int argc, char **argv )
{
    ros::init ( argc, argv, "subscriber_node_2" );
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe ( "chatter", 1000, chatterCallback );
    ros::spin();
	
return 0;
}