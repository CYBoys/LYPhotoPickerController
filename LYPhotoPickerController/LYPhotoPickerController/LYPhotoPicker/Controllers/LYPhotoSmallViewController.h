//
//  LYPhotoSmallViewController.h
//  LYPhotoPickerController
//
//  Created by LaiYoung_ on 2017/3/10.
//  Copyright © 2017年 LaiYoung_. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LYPhotoAssetObject,LYPhotoObject,PHAsset;

@interface LYPhotoSmallViewController : UIViewController
/** 小图浏览的相册标题 */
@property(nonatomic,copy) NSString *smallTitle;
/** 小图浏览的数据源 */
@property (nonatomic, strong) NSArray <LYPhotoAssetObject *>*fetchLYSmallAsset;
/** 已经选择照片的总数 */
@property (nonatomic, assign, readonly) NSUInteger selectedAlbumCount;
/** 已经选择的assets */
@property (nonatomic, strong, readonly) NSArray <PHAsset *> *selectedAssets;
/** 删除 selectedItems和selectedPhotoObjects 里所有的数据并将 maxCount 置为0 */
- (void)removeAllObjects;
/** LYPhotoAssetObject 是否存在于 selectedItems 数组中 */
- (BOOL)isExistsLYPhotoAssetObject:(LYPhotoAssetObject *)object;
/** 根据 LYPhotoAssetObject 对象，操作选择的 selectedPhotoObjects 数组*/
- (BOOL)operationSelectedPhotoObjectsWithLYAssetObject:(LYPhotoAssetObject *)lyAssetObject
                                            identifier:(NSString *)identifier
                                                remove:(BOOL)remove
                                               showTip:(BOOL)show;
/** 已经选择的照片的title及对应的选中张数 */
@property (nonatomic, copy) void(^selectedAlbumTitlesAndNumberBlock)(NSDictionary <NSString *, NSNumber *> *albumTitlesAndNumberDict);
/** 关闭控制器并发送数据，是否原图 */
- (void)clickedSenderWithOriginal:(BOOL)original;

@end