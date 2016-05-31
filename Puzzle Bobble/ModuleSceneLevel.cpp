#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneLevel.h"
#include "ModuleSceneLevel8.h"
#include "ModuleSceneMenu.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleBall.h"
#include "Vector.h"



// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneLevel::ModuleSceneLevel()
{

	//one_ball = new Ball(316,417,16,BLUE);

	//Balls

	// Pipe

	pipe.PushBack({338,1087,13,11});
	pipe2.PushBack({ 354, 1081, 13, 18 });
	
	// Background / sky
	background.x = 0;
	background.y = 0;
	background.w = 320;
	background.h = 240;
	
	// Rueda Animation
	wheel.x = 320;
	wheel.y = 789;
	wheel.w = 16;
	wheel.h = 16;

	// Bub animation static
	bub_static.PushBack({ 114, 53 , 24, 19 });
	bub_static.PushBack({ 147,53, 24, 19 });
	bub_static.PushBack({182, 53, 24, 19 });
	bub_static.PushBack({ 216, 53, 24, 19 });
	bub_static.PushBack({ 249, 53, 24, 19 });
	bub_static.PushBack({ 283, 53, 24, 19 });
	
	bub_static.speed = 0.039f;

	//left bub

	left_bub.PushBack({ 16, 17, 17, 19 });
	left_bub.PushBack({ 254, 19, 17, 17 });
	left_bub.PushBack({ 288, 18, 22, 18 });
	left_bub.PushBack({ 322, 18, 22, 18 });

	left_bub.speed = 0;

	// bub animation
	bub.PushBack({8, 220, 27, 19});
	bub.PushBack({42, 220, 28, 19});
	bub.PushBack({ 76, 220, 31, 19 });
	bub.PushBack({ 110,220, 31, 19 }); 
	bub.PushBack({144, 220, 29, 19 });
	bub.PushBack({178, 220, 28, 19 });
	bub.PushBack({212, 220, 26, 19 });
	bub.PushBack({246, 220, 26, 19 });
	
	bub.speed = 0.3f;

	//bub 2
	bub2.PushBack({ 246, 220, 26, 19 });
	bub2.PushBack({ 212, 220, 26, 19 });
	bub2.PushBack({ 178, 220, 28, 19 });
	bub2.PushBack({ 144, 220, 29, 19 });
	bub2.PushBack({ 110, 220, 31, 19 });
	bub2.PushBack({ 76, 220, 31, 19 });
	bub2.PushBack({ 42, 220, 28, 19 });
	bub2.PushBack({ 8, 220, 27, 19 });
	bub2.speed = 0.3f;

	arrowRect = { 15, 514, 22, 55 };
	//launcher 
/*	launcher2.x = 50;
	launcher2.y = 1020;
	launcher2.w = 56;
	launcher2.h=40 ;
	*/
	//Bag
	bag.x = 358;
	bag.y = 833;
	bag.w = 56;
	bag.h = 24;

	//launcher animation
	launcher.PushBack({ 50, 1020, 56, 40 });
	launcher.PushBack({ 50, 1077, 56, 40 });
	launcher.PushBack({ 50, 1131, 56, 40 });
	launcher.PushBack({ 116, 1020, 56, 40 });
	launcher.PushBack({ 116, 1077, 56, 40 });
	launcher.PushBack({ 116, 1131, 56, 40 });
	launcher.PushBack({ 182, 1020, 56, 40 });
	launcher.PushBack({ 182, 1077, 56, 40 });
	launcher.PushBack({ 182, 1131, 56, 40 });
	launcher.PushBack({ 248, 1020, 56, 40 });
	launcher.PushBack({ 248, 1077, 56, 40 });
	launcher.PushBack({ 248, 1131, 56, 40 });

	launcher.speed = 0.0f;
	/*launcher.PushBack({ 50, 1020, 56, 40 });//2003
	launcher.PushBack({ 121, 2108, 111, 80 });
	launcher.PushBack({ 121, 2212, 111, 80 });
	launcher.PushBack({ 253, 2003, 111, 80 });
	launcher.PushBack({ 253, 2108, 111, 80 });
	launcher.PushBack({ 253, 2212, 111, 80 });
	launcher.PushBack({ 386, 2003, 111, 80 });
	launcher.PushBack({ 386, 2108, 111, 80 });
	launcher.PushBack({ 386, 2212, 111, 80 });
	launcher.PushBack({ 518, 2003, 111, 80 });
	launcher.PushBack({ 518, 2108, 111, 80 });
	launcher.PushBack({ 518, 2212, 111, 80 });

	launcher.speed = 0.3f;*/
	
	// for moving the foreground
	//foreground_pos = 0;
//	forward = true;
}

ModuleSceneLevel::~ModuleSceneLevel()
{
	//delete one_ball;
}


// Load assets
bool ModuleSceneLevel::Start()
{
	App->currentscene = this;
	LOG("Loading lvl scene");

	App->player->Enable();
	App->ball_controll->Enable();

	graphics = App->textures->Load("Sprites and sound/Level7.png");
	graphics_sprite = App->textures->Load("Sprites and sound/spritespuzzle.png");

	App->audio->PlayMusic("Sprites and sound/level_music.ogg", 1.0f);

	throw_effect = App->audio->Load_effects("Sprites and sound/throw_effect.wav");
	
/*	App->ball_controll->AddBall(0, 0, RED);
	App->ball_controll->AddBall(1, 0, RED);
	App->ball_controll->AddBall(2, 0, YELLOW);*/
	App->ball_controll->AddBall(3, 0, PURPLE);
	App->ball_controll->AddBall(4, 0, YELLOW);
	/*App->ball_controll->AddBall(5, 0, BLUE);
	App->ball_controll->AddBall(6, 0, GREEN);
	App->ball_controll->AddBall(7, 0, GREEN);// Bobble level 7*/

//	App->ball_controll->AddBall(0, 1, RED);
//	App->ball_controll->AddBall(1, 1, RED);
	App->ball_controll->AddBall(2, 1, RED);
	App->ball_controll->AddBall(3, 1, GREEN);
	App->ball_controll->AddBall(4, 1, YELLOW);
//	App->ball_controll->AddBall(5, 1, BLUE);
//	App->ball_controll->AddBall(6, 1, GREEN); //7

	////
	/*App->ball_controll->AddBall(0, 2, BLUE);
	App->ball_controll->AddBall(1, 2, BLUE);
	App->ball_controll->AddBall(2, 2, GREEN);*/
	App->ball_controll->AddBall(3, 2, BLUE);
	App->ball_controll->AddBall(4, 2, YELLOW);
	/*App->ball_controll->AddBall(5, 2, RED);
	App->ball_controll->AddBall(6, 2, YELLOW);
	App->ball_controll->AddBall(7, 2, YELLOW);// Bobble level*/

//	App->ball_controll->AddBall(0, 3, BLUE);
//	App->ball_controll->AddBall(1, 3, GREEN);
	App->ball_controll->AddBall(1, 3, YELLOW);
	App->ball_controll->AddBall(2, 3, ORANGE);
	//App->ball_controll->AddBall(4, 3, RED);
	App->ball_controll->AddBall(4, 3, PURPLE);
	App->ball_controll->AddBall(5, 3, PURPLE);

	//App->ball_controll->AddBall(0, 4, BLUE);
	App->ball_controll->AddBall(1, 4, RED);
	App->ball_controll->AddBall(2, 4, RED); 
	App->ball_controll->AddBall(3, 4, YELLOW);
	App->ball_controll->AddBall(4, 4, RED);
	App->ball_controll->AddBall(5, 4, ORANGE);
	App->ball_controll->AddBall(6, 4, PURPLE);
	//App->ball_controll->AddBall(7, 4, YELLOW);

	//App->ball_controll->AddBall(0, 4, BLUE);
	App->ball_controll->AddBall(1, 5, ORANGE);
	App->ball_controll->AddBall(2, 5, PURPLE);
	//App->ball_controll->AddBall(3, 5, YELLOW);
	App->ball_controll->AddBall(4, 5, PURPLE);
	App->ball_controll->AddBall(5, 5, BLUE);
	//App->ball_controll->AddBall(6, 5, PURPLE);
	//App->ball_controll->AddBall(7, 4, YELLOW);

	App->ball_controll->CreateBall();

	return true;
}

// UnLoad assets
bool ModuleSceneLevel::CleanUp()
{
	LOG("Unloading lvl scene");
	App->player->Disable();
	if (App->ball_controll->IsEnabled())
		App->ball_controll->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneLevel::Update()
{
	
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background);
	

	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN || App->ball_controll->array.size()==0)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_level8);
	}

	//wheel

	


	// Bub
	
	
	launcher.speed = 0.0f;
	App->render->Blit(graphics_sprite, 130, 192, &(launcher.GetCurrentFrame()), 0.75f); // launcher 

	
	
	App->render->Blit(graphics_sprite, 179, 213, &(bub_static.GetCurrentFrame()), 0.75f);

	//	App->render->Blit(graphics, 0, (int)foreground_pos, &foreground, 0.92f);
	//	App->render->Blit(graphics, 253, (int)foreground_pos, &foreground, 0.92f);

		//App->render->Blit(graphics, 0, 170, &ground);
		

	/*if (App->input->keyboard[SDL_SCANCODE_1] == KEY_DOWN)
	{
	//	App->ball_controll->GetPos( pos_x,  pos_y);

		if (App->ball_controll->moving_ball == NULL)

		{
			App->ball_controll->CreateBall();
		}
			


	}*/
	if (App->ball_controll->moving_ball->flash==true)
	{
		//look this
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT)
	{	
		if (shoot_angle <= 165){
			launcher.speed = 0.3f;
			App->render->Blit(graphics_sprite, 130, 192, &(launcher.GetCurrentFrame()), 0.75f); // launcher animation

			App->render->Blit(graphics_sprite, 174, 213, &(bub2.GetCurrentFrame()), 0.02f); // Bub animation
			shoot_angle += 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT)
	{	
		if (shoot_angle >= 15)
		{
			launcher.speed = 0.3f;
			App->render->Blit(graphics_sprite, 130, 192, &(launcher.GetCurrentFrame()), 0.75f); // launcher animation

			App->render->Blit(graphics_sprite, 174, 213, &(bub.GetCurrentFrame()), 0.02f); // Bub animation

			shoot_angle -= 1;
		}
	}
	App->render->Blit(graphics_sprite, 151, 180, &arrowRect, 1.0f, 90 - shoot_angle);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		if (App->ball_controll->moving_ball != NULL)
		{
			if (App->ball_controll->moving_ball->moving == false)
			{
				left_bub.speed = 0.3f;
				pipe.speed = 0.05;
				App->ball_controll->ShootBall(shoot_angle);
			
	
			}
			
		}
		Mix_PlayChannel(-1, throw_effect, 0);
	}
	App->render->Blit(graphics_sprite, 136, 213, &(left_bub.GetCurrentFrame()), 0.75f);
	
	//App->render->Blit(graphics_sprite, 154, 215, &(pipe.GetCurrentFrame()), 0.75f);
	App->render->Blit(graphics_sprite, 86, 209, &bag, 0.75f); // Bag 
	App->render->Blit(graphics, 179, 213, &wheel);
	App->render->Blit(graphics_sprite, 154, 215, &(pipe.GetCurrentFrame()), 0.75f);
	/*if (bub2.current_frame == 0)
	{
		bub2.speed = 0;
	}*/
	if (pipe.current_frame == 0)
	{
		pipe.speed = 0;
	}
	if (left_bub.current_frame == 0)
	{
		left_bub.speed = 0;
	}
	return UPDATE_CONTINUE;

}
