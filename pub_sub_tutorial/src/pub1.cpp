#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main ( int argc, char **argv )
{
    ros::init ( argc, argv, "publisher_node_1" );
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String> ( "chatter", 1000 );
    ros::Rate loop_rate ( 10 );

    int count = 0;
	
	std_msgs::String msg;
    std::stringstream ss;

    while ( ros::ok() )
    {	
        ss.str(std::string());
		ss << "Hello ROS! This message's count is: " << count;
        msg.data = ss.str();
        ROS_INFO ( "Sending:\n%s\n", msg.data.c_str() );
        chatter_pub.publish ( msg );
		
		ss.str(std::string());
		ss << "Merhaba ROS! Bu mesajin sayisi: " << count;
		msg.data = ss.str();
		ROS_INFO ( "Sending:\n%s\n", msg.data.c_str() );
        chatter_pub.publish ( msg );
		
		ss.str(std::string());
		ss << "Hola ROS! contar de este mensaje: " << count;
		msg.data = ss.str();
		ROS_INFO ( "Sending:\n%s\n", msg.data.c_str() );
        chatter_pub.publish ( msg );
		
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    
return 0;
}