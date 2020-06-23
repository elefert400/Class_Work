/**
 * @file execute.c
 *
 * @brief Implements interface functions between Quash and the environment and
 * functions that interpret an execute commands.
 *
 * @note As you add things to this file you may want to change the method signature
 */
 //background status, passing current process into create process
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

// open, close and  write to file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "execute.h"
#include "quash.h"
#include "deque.h"




// Remove this and all expansion calls to it
/**
 * @brief Note calls to any function that requires implementation
 */
#define IMPLEMENT_ME()                                                  \
  fprintf(stderr, "IMPLEMENT ME: %s(line %d): %s()\n", __FILE__, __LINE__, __FUNCTION__)

//sets up deque struct for processes
IMPLEMENT_DEQUE_STRUCT(piddeque, pid_t);
//sets up deque functions
PROTOTYPE_DEQUE(piddeque, pid_t);
IMPLEMENT_DEQUE(piddeque, pid_t);
//sets up job deque
typedef struct job_t
{
  piddeque process_list;
  int job_id;
  char* cmd;
}job_t;

IMPLEMENT_DEQUE_STRUCT(BG_job, job_t);
PROTOTYPE_DEQUE(BG_job, job_t);
//sets up functions for deque
IMPLEMENT_DEQUE(BG_job, job_t);


//jobs contructor
static job_t _new_job()
{
  return(job_t){
    new_piddeque(1),
    0,
    get_command_string(),
  };
}

BG_job bg_jobs;

//needs work
//implement destructor, free process command and destroy process deque
static void _destroy_job(job_t b)
{
  //getting the size and using it and the destructor to deallocate the process dequeue
  if(b.cmd != NULL) free(b.cmd);
  destroy_piddeque(&b.process_list);
}

//declares job deque, needs to initalize in the start of run_script
piddeque queue;

//delcaring pipes
int pipes[2][2];
//ex: pipes[0][1] write end of pipe 0
//keeps track of which pipe we are using and %2 it to see which pipe we need to use
int pipeUsed = 0;

//max file size
#define SIZE 512
/***************************************************************************
 * Interface Functions
 ***************************************************************************/

// Return a string containing the current working directory.
char* get_current_directory(bool* should_free) {
  // TODO: Get the current working directory. This will fix the prompt path.
  // HINT: This should be pretty simple
  //IMPLEMENT_ME();
  *should_free = true;
  //char* dbuff = getcwd(NULL, 0);
  // Change this to true if necessary
  /*if (should_free==true){
    should_free = true;
  }*/

  return getcwd(NULL, SIZE);
}

// Returns the value of an environment variable env_var
const char* lookup_env(const char* env_var) {
  // TODO: Lookup environment variables. This is required for parser to be able
  // to interpret variables from the command line and display the prompt
  // correctly
  // HINT: This should be pretty simple
  //IMPLEMENT_ME();
  //char* var = getenv(env_var);
  // TODO: Remove warning silencers
  //(void) env_var; // Silence unused variable warning

  return getenv(env_var);
}

// Check the status of background jobs
void check_jobs_bg_status() {

  if(is_empty_BG_job(&bg_jobs)) return;

  int jobQueueLength = length_BG_job(&bg_jobs);

  //go through every job in the list
  for(int k = 0; k < jobQueueLength; k++)
  {
    job_t temp = pop_front_BG_job(&bg_jobs);
    int firstProcess = peek_front_piddeque(&temp.process_list);
    int lengthProcessQueue = length_piddeque(&temp.process_list);

    //go through every process in a job
    for(int i = 0; i < lengthProcessQueue; i++)
    {
      int stat = 0;
      pid_t tempProcess = pop_front_piddeque(&temp.process_list);
      if(waitpid(firstProcess, &stat, WNOHANG) == 0)
      {
        //wanna look here
        push_back_BG_job(&temp.process_list, temp);
      }

      if(is_empty_piddeque(&temp.process_list))
      {
        print_job_bg_complete(temp.job_id, tempProcess, temp.cmd);
        _destroy_job(temp);
      }
      else
      {
        push_back_BG_job(&bg_jobs, temp);
      }
    }
  }
  // TODO: Check on the statuses of all processes belonging to all background
  // jobs. This function should remove jobs from the jobs queue once all
  // processes belonging to a job have completed.
  //IMPLEMENT_ME();

  // TODO: Once jobs are implemented, uncomment and fill the following line
  // print_job_bg_complete(job_id, pid, cmd);
}

// Prints the job id number, the process id of the first process belonging to
// the Job, and the command string associated with this job
void print_job(int job_id, pid_t pid, const char* cmd) {
  printf("[%d]\t%8d\t%s\n", job_id, pid, cmd);
  fflush(stdout);
}

// Prints a start up message for background processes
void print_job_bg_start(int job_id, pid_t pid, const char* cmd) {
  printf("Background job started: ");
  print_job(job_id, pid, cmd);
}

// Prints a completion message followed by the print job
void print_job_bg_complete(int job_id, pid_t pid, const char* cmd) {
  printf("Completed: \t");
  print_job(job_id, pid, cmd);
}

/***************************************************************************
 * Functions to process commands
 ***************************************************************************/
// Run a program reachable by the path environment variable, relative path, or
// absolute path
void run_generic(GenericCommand cmd) {
  // Execute a program with a list of arguments. The `args` array is a NULL
  // terminated (last string is always NULL) list of strings. The first element
  // in the array is the executable
  char* exec = cmd.args[0];
  char** args = cmd.args;

  // TODO: Remove warning silencers
  execvp(exec, args); // Silence unused variable warning

  // TODO: Implement run generic


  perror("ERROR: Failed to execute program");
}

// Print strings
void run_echo(EchoCommand cmd) {
  // Print an array of strings. The args array is a NULL terminated (last
  // string is always NULL) list of strings.
  char** str = cmd.args;

  // TODO: Remove warning silencers
  //(void) str; // Silence unused variable warning

  // TODO: Implement echo
  //IMPLEMENT_ME();
  //int size =
  for(int i = 0; i < sizeof(str);i++){
    if (str[i] != NULL)
    {
      printf("%s ", str[i]);
    }
  }
  printf("\n");
  // Flush the buffer before returning
  fflush(stdout);
}

// Sets an environment variable
void run_export(ExportCommand cmd) {
  // Write an environment variable
  const char* env_var = cmd.env_var;
  const char* val = cmd.val;

  // TODO: Remove warning silencers
  //(void) env_var; // Silence unused variable warning
  //(void) val;     // Silence unused variable warning

  // TODO: Implement export.
  // HINT: This should be quite simple.
  //IMPLEMENT_ME();
  //changes env_var value to val and since parameter 3 is 1 it overwrites it
  setenv(env_var, val, 1);
}

// Changes the current working directory
void run_cd(CDCommand cmd) {
  // Get the directory name
  const char* dir = cmd.dir;

  //char path[PATH_MAX+1];

  // Check if the directory is valid
  if (dir == NULL) {
    perror("ERROR: Failed to resolve path");
    return;
  }
  // TODO: Change directory

  char* oldDir = getcwd(NULL, SIZE);

  chdir(dir);

  char* newDir = getcwd(NULL, SIZE);
  // char realPath[PATH_MAX +1];
  // chdir (realpath(dir, realPath));
  // TODO: Update the PWD environment variable to be the new current working
  // directory and optionally update OLD_PWD environment variable to be the old
  // working directory.
  setenv("PWD", newDir, 1);
  setenv("OLD_PWD", oldDir, 1);
  // setenv("OLD_PWD", lookup_env("PWD"), 1);
  // setenv("PWD", dir, 1);
  //IMPLEMENT_ME();

  free(oldDir);
  free(newDir);
}

// Sends a signal to all processes contained in a job
void run_kill(KillCommand cmd) {
  int signal = cmd.sig;
  int job_id = cmd.job;

  int jobQueueLength = length_BG_job(&bg_jobs);

  for(int k = 0; k < jobQueueLength; k++)
  {
    
  }

  // TODO: Remove warning silencers
  //(void) signal; // Silence unused variable warning
  //(void) job_id; // Silence unused variable warning

  // TODO: Kill all processes associated with a background job
  //IMPLEMENT_ME();
}


// Prints the current working directory to stdout
void run_pwd() {
  // TODO: Print the current working directory
  //IMPLEMENT_ME();
  //used get current directory and free it
  bool should_free = false;
  char* dbuff = get_current_directory(&should_free);
  printf("\nDirectory:%s \n", dbuff);
  if (should_free) free(dbuff);
  // Flush the buffer before returning
  fflush(stdout);
  return;
}

// Prints all background jobs currently in the job list to stdout
void run_jobs() {
  // TODO: Print background jobs
  IMPLEMENT_ME();
  if (is_empty_BG_job(&bg_jobs)) return;

  int length = length_BG_job(&bg_jobs);
  for(int i=0; i<length;i++){
    job_t curr_job = pop_front_BG_job(&bg_jobs);
    print_job(curr_job.job_id, peek_front_piddeque(&curr_job.process_list), curr_job.cmd);
    push_back_BG_job(&bg_jobs, curr_job);
  }

  // Flush the buffer before returning
  fflush(stdout);
}

/***************************************************************************
 * Functions for command resolution and process setup
 ***************************************************************************/

/**
 * @brief A dispatch function to resolve the correct @a Command variant
 * function for child processes.
 *
 * This version of the function is tailored to commands that should be run in
 * the child process of a fork.
 *
 * @param cmd The Command to try to run
 *
 * @sa Command
 */
void child_run_command(Command cmd) {
  CommandType type = get_command_type(cmd);

  switch (type) {
  case GENERIC:
    run_generic(cmd.generic);
    break;

  case ECHO:
    run_echo(cmd.echo);
    break;

  case PWD:
    run_pwd();
    break;

  case JOBS:
    run_jobs();
    break;

  case EXPORT:
  case CD:
  case KILL:
  case EXIT:
  case EOC:
    break;

  default:
    fprintf(stderr, "Unknown command type: %d\n", type);
  }
}

/**
 * @brief A dispatch function to resolve the correct @a Command variant
 * function for the quash process.
 *
 * This version of the function is tailored to commands that should be run in
 * the parent process (quash).
 *
 * @param cmd The Command to try to run
 *
 * @sa Command
 */
void parent_run_command(Command cmd) {
  CommandType type = get_command_type(cmd);

  switch (type) {
  case EXPORT:
    run_export(cmd.export);
    break;

  case CD:
    run_cd(cmd.cd);
    break;

  case KILL:
    run_kill(cmd.kill);
    break;

  case GENERIC:
  case ECHO:
  case PWD:
  case JOBS:
  case EXIT:
  case EOC:
    break;

  default:
    fprintf(stderr, "Unknown command type: %d\n", type);
  }
}

/**
 * @brief Creates one new process centered around the @a Command in the @a
 * CommandHolder setting up redirects and pipes where needed
 *
 * @note Processes are not the same as jobs. A single job can have multiple
 * processes running under it. This function creates a process that is part of a
 * larger job.
 *
 * @note Not all commands should be run in the child process. A few need to
 * change the quash process in some way
 *
 * @param holder The CommandHolder to try to run
 *
 * @sa Command CommandHolder
 */
void create_process(CommandHolder holder, job_t* curr_job) {
  // Read the flags field from the parser
  bool p_in  = holder.flags & PIPE_IN;
  bool p_out = holder.flags & PIPE_OUT;
  bool r_in  = holder.flags & REDIRECT_IN;
  bool r_out = holder.flags & REDIRECT_OUT;
  bool r_app = holder.flags & REDIRECT_APPEND; // This can only be true if r_out
                                               // is true

  pid_t pid;
  // TODO: Setup pipes, redirects, and new process
  if(p_out)
  {
    pipe(pipes[pipeUsed % 2]);
  }
  pid = fork();
  //child
  if (pid == 0){
    //redirect to the same place
    if(r_in){
      //int in = open(holder.redirect_in, O_RDONLY);
      FILE* in = fopen(holder.redirect_in, "r");
      dup2(fileno(in), STDIN_FILENO);
      fclose(in);
    }
    //redirect to a file
    if (r_out){
      FILE* newFile;
      //check if it is an appending
      if(r_app){
        newFile = fopen(holder.redirect_out, "a");
      }
      else{
        newFile = fopen(holder.redirect_out, "w");
      }
      dup2(fileno(newFile), STDOUT_FILENO);
      //because we are using a file fclose()
      fclose(newFile);
    }
    // I have no clue how to do this or any pipe thing SORRY!!!
    //if pipe in
    if(p_in){
      //make a copy
      //pipe[][0]
      close(pipes[pipeUsed % 2][1]);
      dup2(pipes[pipeUsed % 2][0], STDIN_FILENO);
      pipeUsed++;
      close(pipes[pipeUsed % 2][0]);
      close(pipes[pipeUsed % 2][1]);
    }
    if(p_out)
    {
      dup2(pipes[pipeUsed % 2][0], STDOUT_FILENO);
      close(pipes[pipeUsed % 2][1]);
      pipeUsed++;
      close(pipes[pipeUsed % 2][0]);
      close(pipes[pipeUsed % 2][1]);
    }

    child_run_command(holder.cmd);
    //destroy the job
    exit (EXIT_SUCCESS);
  }//end child
  else{//parent branch
    //check if pipe out
    if(p_out){
      //pipe[][1]
      close(pipes[pipeUsed % 2][0]);
      dup2(pipes[pipeUsed % 2][1], STDOUT_FILENO);
      pipeUsed++;
      close(pipes[pipeUsed % 2][0]);
      close(pipes[pipeUsed % 2][1]);
    }
    // if(p_in){
    //   //pipe[][0]
    //   dup2(pipes[pipeUsed % 2][0], STDIN_FILENO);
    //   close(pipes[pipeUsed % 2][1]);
    //   pipeUsed++;
    //   close(pipes[pipeUsed % 2][0]);
    //   close(pipes[pipeUsed % 2][1]);
    //   //push the process to the front of the q
    //   parent_run_command(holder.cmd);
    // }
     parent_run_command(holder.cmd);
}//end parent
}
// Run a list of commands
void run_script(CommandHolder* holders) {
  if (holders == NULL)
    return;

  check_jobs_bg_status();

  if (get_command_holder_type(holders[0]) == EXIT &&
      get_command_holder_type(holders[1]) == EOC) {
    end_main_loop();
    return;
  }

  CommandType type;
  //create a new job to hold the current job, call the constructor
  job_t curr_job = _new_job();

  // Run all commands in the `holder` array
  for (int i = 0; (type = get_command_holder_type(holders[i])) != EOC; ++i)
    create_process(holders[i], &curr_job);

  if (!(holders[0].flags & BACKGROUND)) {
    // Not a background Job
    // TODO: Wait for all processes under the job to complete
    //need another wait (waitpid) to wait the perfect amount of time
    while (!is_empty_piddeque(&curr_job.process_list)){
    int status;
    //-1 will wait untill the child process ends correctly
    if(waitpid(peek_back_piddeque(&curr_job.process_list), &status, 0 != -1)){
      //pop changes the value of the last element in the q while peek does not
      pop_back_piddeque(&curr_job.process_list);
      }
    }
  }
  else {
    // A background job.
    curr_job.cmd = get_command_string();
    //need a global job_id to keep the total number correct.
    //curr_job.job_id = job_id++;
    //add the background job to the end of the q
    push_back_BG_job(&bg_jobs, curr_job);

    // TODO: Push the new job to the job queue
    //figure out new job ID and push it to the back of the job queue and print that the background job has started

    IMPLEMENT_ME();

    // TODO: Once jobs are implemented, uncomment and fill the following line
    //print the first element in the pid q (which what peek returns)
    print_job_bg_start(curr_job.job_id,peek_front_piddeque(&curr_job.process_list), curr_job.cmd);
  }
}
