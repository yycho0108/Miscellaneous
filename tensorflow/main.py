import tensorflow as tf
import numpy as np


if __name__ == "__main__":
    I = np.random.rand(1,5,5,1)
    print I
    I = np.asarray(I, dtype=np.float32)
    g = tf.Graph()

    with g.as_default():
        tf_I = tf.constant(I)
        W = tf.Variable(tf.truncated_normal([3,3,1,1],stddev=0.1))
        tf_O = tf.nn.conv2d(tf_I, W, [1, 2, 2, 1], padding='SAME', use_cudnn_on_gpu = False) 

        tf_O_2 = tf.nn.conv2d(tf_I, W, [1, 1, 1, 1], padding='SAME', use_cudnn_on_gpu = False) 
        tf_O_2 = tf.nn.max_pool(tf_O_2,[1,2,2,1],[1,2,2,1],'SAME')

        #EXCERPT_1
#         conv = tf.nn.conv2d(data, layer1_weights, [1, 2, 2, 1], padding='SAME', use_cudnn_on_gpu = False)
#         hidden = tf.nn.relu(conv + layer1_biases)
#     
        #EXCERPT
#         conv = tf.nn.conv2d(data, layer1_weights, [1, 1, 1, 1], padding='SAME', use_cudnn_on_gpu = False)
#         pool = tf.nn.max_pool(conv, [1,2,2,1], [1,2,2,1], 'SAME')
#         hidden = tf.nn.relu(conv + layer1_biases)
    

    with tf.Session(graph=g) as session:
        tf.initialize_all_variables().run()
        O,O_2 = session.run([tf_O,tf_O_2])

        print "O", O
        print "O_2", O_2

        print O.shape

        print O_2.shape
