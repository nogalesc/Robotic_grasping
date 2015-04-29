Editor: Chris Nogales
---------------------------------------------------------------
------------HOW TO EXTRACT FEATURES----------------------------
---------------------------------------------------------------
This is the original README file from the svmlight package that Ms. Jiang provided, 
she refers to it as the LimClassifier. 

How I run it: 
$ roscd ~/electric_workspace/sandbox/svmlight/
$ rosrun svmlight extract_pc_features ~/data_for_training 424 

-> I use 424 because only 50% of the data is used for training
-> The folder contains 900 samples but we skip half

---------------------------------------------------------------
------------HOW TO CREATE MODEL--------------------------------
---------------------------------------------------------------
For the second step, you have to use the executable called svm_learn at ~/experimentCode/svm_light/svm_learn.
This executable comes from a free-to-use library (svmlight.joachims.org) and it will create a model file.
$ ./svm_learn ~/backup_of_features/features model 

For the final step, come back here.

Author: Chris Nogales
Content: This document shows how to train using the features file extracted. It also shows the results.


shockwave@ubuntu:~/Downloads/svm_light_linux64$ ./svm_learn ~/backup_of_features/features model
Scanning examples...done
Reading examples into memory...100..200..300..400..500..600..700..800..900..1000..1100..1200..1300..1400..1500..1600..1700..1800..1900..2000..2100..2200..2300..2400..2500..2600..2700..2800..2900..3000..3100..3200..3300..3400..3500..3600..3700..3800..OK. (3833 examples read)
Setting default regularization parameter C=0.0003
Optimizing..................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................done. (1715 iterations)
Optimization finished (652 misclassified, maxdiff=0.00100).
Runtime in cpu-seconds: 4.27
Number of SV: 1817 (including 1813 at upper bound)
L1 loss: loss=1697.15400
Norm of weight vector: |w|=0.18469
Norm of longest example vector: |x|=193.65805
Estimated VCdim of classifier: VCdim<=911.02720
Computing XiAlpha-estimates...done
Runtime for XiAlpha-estimates in cpu-seconds: 0.01
XiAlpha-estimate of the error: error<=47.40% (rho=1.00,depth=0)
XiAlpha-estimate of the recall: recall=>63.02% (rho=1.00,depth=0)
XiAlpha-estimate of the precision: precision=>63.04% (rho=1.00,depth=0)
Number of kernel evaluations: 137804
Writing model file...done

---------------------------------------------------------------
------------ORIGINAL INSTRUCTIONS------------------------------
---------------------------------------------------------------

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

---------------------------------------------------------------
------------HOW TO RANK RECTANGLES USING MODEL-----------------
---------------------------------------------------------------
$./bin/rank ./pcd0199r.png ./pcdb0013r.png ./pcd0199.txt model /tmp/scm42/


