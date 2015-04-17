# Robotic_grasping: data

The data used to train the SVM can be found here: http://pr.cs.cornell.edu/grasping/rect_data/data.php

*They are missing data 00 and the code cannot run without it so I renamed files in 10*

Place only raw data in ~/data_for_training/

# Robotic_grasping: Set up

1. Install Ubuntu 10.04.4 LTS (lucid) in a computer
2. Install ROS electric
3. Create a ~/electric_workspace
4. Create a package called svmlight

# Robotic_grasping: To run the code
1. First extract features 
$ rosrun vsmlight extract_pc_features $PATH_TO_DATA/ #

*# = How many samples to train on, I set it to half the max available because it SKIPS samples! 

