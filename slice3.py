#
//  slice3.py
//  
//
//  Created by Xinhong WU on 11.02.26.
//

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 21 12:56:18 2025

@author: xinhong.wu
"""




import numpy as np
import os
import matplotlib.pyplot as plt
import napari


def crop_and_pad( crop_size,image_3d):
    """Crop or pad the 3D data to match the target crop size."""

    print(f"image shape: {image_3d.shape}")
    # print(f"Mask  shape: {mask_3d.shape}")
    H_target, W_target = crop_size
    H, W, D = image_3d.shape  # Keep the depth dimension (D) unchanged

    # Crop in height (H) if necessary
    if H > H_target:
        start_h = (H - H_target) // 2
        image_3d = image_3d[start_h:start_h + H_target, :, :]
        # mask_3d = mask_3d[start_h:start_h + H_target, :, :]

    # Crop in width (W) if necessary
    if W > W_target:
        start_w = (W - W_target) // 2
        image_3d = image_3d[:, start_w:start_w + W_target, :]
        # mask_3d = mask_3d[:, start_w:start_w + W_target, :]

    # Pad if the height (H) is smaller than the target
    if H < H_target:
        pad_h = H_target - H
        pad_h_top = pad_h // 2
        pad_h_bottom = pad_h - pad_h_top
        image_3d = np.pad(image_3d, ((pad_h_top, pad_h_bottom), (0, 0), (0, 0)),  mode='reflect')
                          # mode='constant',constant_values=0)
        # mask_3d = np.pad(mask_3d, ((pad_h_top, pad_h_bottom), (0, 0), (0, 0)), mode='edge')

    # Pad if the width (W) is smaller than the target
    if W < W_target:
        pad_w = W_target - W
        pad_w_left = pad_w // 2
        pad_w_right = pad_w - pad_w_left
        image_3d = np.pad(image_3d, ((0, 0), (pad_w_left, pad_w_right), (0, 0)), mode='reflect')
                          # ,mode='constant',constant_values=0)
        # mask_3d = np.pad(mask_3d, ((0, 0), (pad_w_left, pad_w_right), (0, 0)), mode='edge')
        #
    image_3d = image_3d.astype(np.float32)
    # mask_3d = mask_3d.astype(np.int64)

    return image_3d
# 输入文件夹和输出文件夹
input_image_dir = '/project/med6/SpecCT/tran13.08/simulatedCT3bins/'

# output_image_dir = '/scratch-local/rawdata/contrast/'

# os.makedirs(output_image_dir, exist_ok=True)

# 设置裁剪大小
crop_size = (256, 256)  # 示例大小，根据需求调整

# 调用处理函数
# process_and_save(input_image_dir,  crop_size)

# def process_and_save(input_image_dir, crop_size):
# 确保输出文件夹存在
# os.makedirs(output_image_dir, exist_ok=True)
# os.makedirs(output_mask_dir, exist_ok=True)

# 获取文件夹中所有的 .npy 文件，并按名称排序
image_files = sorted([f for f in os.listdir(input_image_dir) if f.endswith('_all.npy')])
# mask_files = sorted([f for f in os.listdir(input_mask_dir) if f.endswith('.npy')])
# if len(image_files) != len(mask_files):
    # raise ValueError("The number of image files does not match the number of mask files.")

# 逐个处理文件
for image_file  in image_files:
    # 加载3D图像和mask
    if '002h' not in image_file:
        # continue
        output_image_dir = '/scratch-local/rawdata/contrast/traindata/bin3_1e4'
        # output_mask_dir = '/scratch-local/rawdata/contrast/traindata/sNCT2dmask'
    else:
        output_image_dir = '/scratch-local/rawdata/contrast/testdata/bin3_1e4'
        # output_mask_dir = '/scratch-local/rawdata/contrast/testdata/sNCT2dmask'
    # Create output folders if they don't exist
    os.makedirs(output_image_dir, exist_ok=True)
    # os.makedirs(output_mask_dir, exist_ok=True)
    # 加载3D图像和mask
    prefix = image_file.split('_all')[0]
    bin1_path = os.path.join(input_image_dir, f'{prefix}_bin1.npy')
    bin2_path = os.path.join(input_image_dir, f'{prefix}_bin2.npy')
    bin3_path = os.path.join(input_image_dir, f'{prefix}_bin3.npy')
    image_bin3_3d = np.load(bin3_path).transpose(2,1,0)
    image_bin2_3d = np.load(bin2_path).transpose(2,1,0)
    image_bin1_3d = np.load(bin1_path).transpose(2,1,0)
    # image_H_3d = np.load(os.path.join(input_image_dir, image_file)).transpose(2,1,0)
    # image_3d = image_3d.transpose(1,2,0)
    print(image_bin1_3d.shape)
    # ct_data = np.load('/scratch-local/rawdata/contrast/simulatedCT2bine4/M10_024h_simulated_all.npy')
    # with napari.gui_qt():
    #     viewer = napari.Viewer()
    #     viewer.add_image(ct_data)#, colormap=colormap, name="Colored CT")
    # # image_3d = image_3d[20:-20,20:-20,:]
    # mask_3d = np.load(os.path.join(input_mask_dir, mask_file))
    # print(mask_3d.shape)
    # 应用 crop_and_pad 函数
    plt.imshow(image_bin1_3d[:,:,200],vmax=0.05,vmin =0)
    plt.colorbar()
    plt.show()
    image_bin1_3d = crop_and_pad(crop_size,image_bin1_3d)
    image_bin2_3d = crop_and_pad(crop_size,image_bin2_3d)
    image_bin3_3d = crop_and_pad(crop_size,image_bin3_3d)
    image_2d =np.zeros((3,256,256))
    # 提取每一层并保存为2D图像
    depth = image_bin1_3d.shape[2]
    for idx in range(depth):
        image_2d[0] = image_bin1_3d[:, :,idx]
        image_2d[1] = image_bin2_3d[:, :,idx]
        image_2d[2] = image_bin3_3d[:, :,idx]
        # mask_2d = mask_3d[:, :, idx]
        # plt.imshow(image_2d[:,:,0])
        # plt.show()
      
        # 保存为2D图像
        np.save(os.path.join(output_image_dir, f"{image_file[:-4]}_slice_{idx:04d}.npy"), image_2d)
        
        # np.save(os.path.join(output_mask_dir, f"{mask_file[:-4]}_slice_{idx}.npy"), mask_2d)
        if idx ==0:
            print(f"Saved slice {idx} of {image_file}.")
            print(os.path.join(output_image_dir, f"{image_file[:-4]}_slice_{idx:04d}.npy"))
            print(output_image_dir)
