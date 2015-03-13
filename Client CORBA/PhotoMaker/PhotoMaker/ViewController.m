//
//  ViewController.m
//  PhotoMaker
//
//  Created by Stas on 13.03.15.
//  Copyright (c) 2015 Distvi. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<UIImagePickerControllerDelegate, UINavigationControllerDelegate>


@property (weak, nonatomic) IBOutlet UIImageView *bgImageView;
@property (weak, nonatomic) IBOutlet UIButton *photoButton;
@property (weak, nonatomic) IBOutlet UIButton *filterButton;
@property (weak, nonatomic) IBOutlet UIView *flagView;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _flagView.alpha = 0.0;
    // Do any additional setup after loading the view, typically from a nib.
}

#pragma mark - IBActions

- (IBAction)makePhoto:(UIButton *)sender {
    [UIView animateWithDuration:0.3 animations:^{
        _flagView.alpha = 0.0;
    } completion:^(BOOL finished) {
        if (finished) {
            UIImagePickerController *picker = [[UIImagePickerController alloc] init];
            picker.delegate = self;
            picker.allowsEditing = YES;
            picker.sourceType = UIImagePickerControllerSourceTypeCamera;
            picker.allowsEditing = NO;
            
            [self presentViewController:picker animated:YES completion:NULL];
        }
    }];
}

- (IBAction)filterPhoto:(UIButton *)sender {
    [UIView animateWithDuration:0.5 animations:^{
        _flagView.alpha = 0.3;
//        self.bgImageView.transform = CGAffineTransformRotate(self.bgImageView.transform, M_PI);
    }];
}

#pragma mark - Image Picker Controller delegate methods

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    
    UIImage *chosenImage = info[UIImagePickerControllerOriginalImage];
    self.bgImageView.image = chosenImage;
    
    [picker dismissViewControllerAnimated:YES completion:NULL];
    
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    
    [picker dismissViewControllerAnimated:YES completion:NULL];
    
}


@end
