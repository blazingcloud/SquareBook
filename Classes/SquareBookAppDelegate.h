//
//  SquareBookAppDelegate.h
//  SquareBook
//
//  Created by Lee Lundrigan on 11/16/10.
//  Copyright 2010 Blazing Cloud, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "GMPageViewController.h"

@interface SquareBookAppDelegate : NSObject <UIApplicationDelegate> {
    IBOutlet GMPageViewController *pageViewController;
    UIWindow *window;
    
    NSManagedObject *configuration;
    
@private
    NSManagedObjectContext *managedObjectContext_;
    NSManagedObjectModel *managedObjectModel_;
    NSPersistentStoreCoordinator *persistentStoreCoordinator_;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (NSURL *)applicationDocumentsDirectory;

@end

