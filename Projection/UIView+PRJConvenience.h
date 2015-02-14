//
//  UIView+PRJProjection.h
//  Projection
//
//  Created by Mikey Lintz on 2/1/15.
//  Copyright (c) 2015 Mikey Lintz. All rights reserved.
//

@class PRJMapping;
@class PRJRect;

typedef void (^PRJConfigurationBlock)(PRJMapping *mapping, PRJRect *viewBounds);

/** Convenience category for applying layout to a view's children.

These methods automatically create an empty PRJMapping and a fully defined PRJRect representing the
receivers frame pass, them to a client-provided PRJConfigurationBlock to fill out the mapping, and
then invokes [mapping apply].

The following two examples are equivalent:

    // Without category method

    PRJMapping *mapping = [[PRJMapping alloc] init];
    PRJRect *viewBounds = [[PRJRect alloc] init];

    viewBounds.bounds = superView.bounds;
    mapping[subview1].topLeft = viewBounds.topLeft;
    mapping[subview1].size = CGSizeMake(10, 10);

    mapping[subview2].bottomRight = viewBounds.bottomRight;
    mapping[subview2].size = mapping[subview1].size;

    [mapping apply];

    // With category method

    [viewBounds prj_applyProjection:^(PRJMapping *mapping, PRJRect *viewBounds) {
      mapping[subview1].topLeft = viewBounds.topLeft;
      mapping[subview1].size = CGSizeMake(10, 10);

      mapping[subview2].bottomRight = viewBounds.bottomRight;
      mapping[subview2].size = mapping[subview1].size;
    }];
*/

@interface UIView (PRJConvenience)

- (void)prj_applyProjection:(PRJConfigurationBlock)configurationBlock;
- (void)prj_applyProjectionWithSize:(CGSize)size
                      configuration:(PRJConfigurationBlock)configurationBlock;
- (void)prj_applyProjectionWithBounds:(CGRect)bounds
                        configuration:(PRJConfigurationBlock)configurationBlock;

@end
