//
//  DemoViewController.m
//  FWDraggableSwipePlayer
//
//  Created by Filly Wang on 20/1/15.
//  Copyright (c) 2015 Filly Wang. All rights reserved.
//

#import "DemoViewController.h"
#import "FWSWipePlayerConfig.h"
#import "MovieDetailView.h"

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

@interface DemoViewController ()
{
    NSMutableArray *list;
    BOOL shouldRotate;
}

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    self.listView.delegate = self;
    self.listView.dataSource = self;
    
    shouldRotate = NO;
    
    NSString *path=[[NSBundle mainBundle] pathForResource:@"list" ofType:@"json"];
    NSData *listData=[NSData dataWithContentsOfFile:path];
    list = [NSJSONSerialization JSONObjectWithData:listData options:NSJSONReadingMutableLeaves error:nil];
    
}

-(void)viewDidAppear:(BOOL)animated
{
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [list count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"tablecell"];
    
    if(cell==nil){
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"tablecell"];
    }
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = list[[indexPath row]][@"title"];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    if(self.playerManager == nil)
    {
        FWSWipePlayerConfig *config = [[FWSWipePlayerConfig alloc]init];
        //self.playerManager = [[FWDraggablePlayerManager alloc]initWithInfo:list[[indexPath row]] Config:config];
        self.playerManager = [[FWDraggablePlayerManager alloc]initWithList:list Config:config];
    }
    else
        [self.playerManager updateInfo:list[[indexPath row]]];
    
    MovieDetailView *detailView = [[MovieDetailView alloc]initWithFrame:self.view.frame];
    [detailView initWithInfo:list[[indexPath row]]];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(handleSwipePlayerViewStateChange:)
                                                 name:FWSwipePlayerViewStateChange object:nil];
    
    [self.playerManager showAtViewAndPlay:self.view];
}

#pragma mark notification
-(void)handleSwipePlayerViewStateChange:(NSNotification *)notity
{
    BOOL isSmall = [[[notity userInfo] valueForKey:@"isSmall"] boolValue];
    BOOL isLock = [[[notity userInfo] valueForKey:@"isLock"] boolValue];
    
    if(isSmall || isLock)
        shouldRotate = NO;
    else if(!isLock && !isSmall)
        shouldRotate = YES;
    else
        shouldRotate = NO;
}


#pragma mark rotata

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return shouldRotate;
}

- (BOOL)shouldAutorotate
{
    return shouldRotate;
}

- (NSUInteger)supportedInterfaceOrientations
{
     return UIInterfaceOrientationMaskAll;
}

@end
