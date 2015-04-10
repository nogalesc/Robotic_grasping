Editor: Chris Nogales
------------------------------------------------------------------------------------
This is the original README file from the svmlight package that Ms. Jiang provided, 
she refers to it as the LimClassifier. 

How I run it: $ rosrun svmlight extract_pc_features ~data/00 100

For the second step, you have to use the executable called svm_learn at ~/experimentCode/svm_light/svm_learn.
This executable comes from a free-to-use library (svmlight.joachims.org) and it will create a model file.

For the final step, come back here.

------------------------------------------------------------------------------------
There are many executables built in this package, and most of them are for internal use only.

You should only be using ./bin/rank 

./bin/rank imgFile bgFile pcdFile <modelFile image_save_dir>

IMPORTANT NOTE:  It assumes that "filters.txt" is present in the working directory!

example:
./bin/rank ./left0002.pgm ./left0001.pgm ./pcd0000.txt model /tmp/scm42/
            rgb image      background       pcd       [model] [image grasp output dir]

First three args specify the (left) image, background image (not disparity) and PointCloud data file to use.
The last two arguments are optional.  modelFile defaults to "model", so if you want to change to a different one you can specify the modelFile.  image_save_dir, if specified, will cause the program to save 2 images depicting the predicted grasping rectangles and 1 image showing the background subtraction mask in the directory specified.

The output of this program is stored in the working directory and is called sr_%04d.txt where %04d is the image number.  Eg left0010.pgm will have image number of 0010 .  All images saved (if image_save_dir is specified) will also contain this image number.  This file contains a list of AT MOST 100 rectangles, sorted in descending order by ranking score.  If the background subtraction is unable to pick out a reasonable mask for the object, there may be less than 100 rectangles considered during search, so the output might have less than 100 rectangles.
